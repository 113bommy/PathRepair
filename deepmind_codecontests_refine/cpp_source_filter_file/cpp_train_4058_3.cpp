#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <cstdio>
#include <cmath>

using namespace std;

string str_week[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "All" };
map<string, int> W;
int s, n, t, p, m;
string week, sTime;

// 時間を進める(分単位)
void addTime ( int &hh, int &mm, int &ww, int x )
{
	static const int day = 24 * 60 * 60;
	static const int hou = 60 * 60;
	static const int min = 60;
	if (!x) { return; }
	int tt = hh * hou + mm * min + x * min;
	if (tt >= day) {
		ww <<= 1;
		tt %= day;
		if (ww >= (1 << 7)) { ww = 1; }
	}
	hh = tt / hou;
	tt %= hou;
	mm = tt / min;
}

// 突然変異可能な曜日・時間帯か調べる
bool isChange ( int hh, int mm, int ww )
{
	if ((W[week] & ww) == 0) { return false; }
	if (sTime == "All") { return true; }
	if (sTime == "Day" && (6 <= hh && hh < 18)) { return true; }
	if (sTime == "Night" && (18 <= hh || hh < 6)) { return true; }
	return false;
}

double prob = 0;

// 確率をシミュレーションする
double getProb ( int hh, int mm, int ww )
{
	double miss = 1.0;
	for (int i = 0; i < m; ++i) {
		bool hit = true;
		hit &= isChange(hh, mm, ww); // 卵の出現した時は変異の範囲内か
		addTime(hh, mm, ww, s);
		hit &= isChange(hh, mm, ww); // 孵化の時は変異の範囲内か
		if (hit) { // 出現から孵化まで変異の範囲内なので変化が起こる(失敗)
			miss *= prob;
		}
		addTime(hh, mm, ww, t - s); // ステージの終了まで時間を進める
	}
	return 1.0 - miss;
}

int main ( void )
{
	W["All"] = (1 << 7) - 1;
	for (int i = 0; i < 7; ++i) {
		W[str_week[i]] = 1 << i;
	}
	while (cin >> s >> n >> t >> week >> sTime >> p >> m) {
		if (s+n+t+p+m == 0 && week == sTime && week == "None") { break; }
		double ans = 0;
		prob = pow((p - 1.0)/ (double)p, n)
		for (int i = 0; i < 7; ++i) {
			for (int j = 0; j < 24; ++j) {
				for (int k = 0; k < 60; ++k) {
					ans = max(ans, getProb(j, k, W[str_week[i]]));
				}
			}
		}
		printf("%.10lf\n", ans);
	}
	return 0;
}