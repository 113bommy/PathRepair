#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) ((a) <= (x) && (x) <= (b))
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define POWT(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define MODU 1000000007
#define bitcheck(a,b)   ((a >> b) & 1)
#define bitset(a,b)      ( a |= (1 << b))
#define bitunset(a,b)    (a &= ~(1 << b))
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const pii Dir[8] = { //?????????
	{ 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 },
	{ 1,1 },{ 1,-1 },{ -1,-1 },{ -1,1 }
};
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	std::fill((T*) array, (T*) (array + N), val);
}

signed main() {
	int r;

	while (scanf("%d", &r)) {
		if (r == 0)
			break;
		int w, h, x, y;
		scanf("%d %d %d %d", &w, &h, &y, &x);
		x--; y--;
		vector<vector<int>> m(h, vector<int>(w));
		REP(i, h) {
			REP(j, w) {
				scanf("%d", &m[i][j]);
			}
		}
		int w2, h2, x2, y2;
		scanf("%d %d %d %d", &w2, &h2, &y2, &x2);
		x2--; y2--;
		vector<vector<int>> m2(h2, vector<int>(w2));

		REP(i, h2) {
			REP(j, w2) {
				scanf("%d", &m2[i][j]);
			}
		}
		priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> que;

		que.push({ 1,{ x,y } });

		map<int, int> mcount;
		vector<vector<int>> al(h, vector<int>(w));
		while (que.size()) {
			int  p = que.top().first;
			pii cur = que.top().second;
			que.pop();
			if (al[cur.first][cur.second])
				continue;
			al[cur.first][cur.second] = 1;
			mcount[p]++;

			REP(i, 4) {
				pii next = { cur.first + Dir[i].first, cur.second + Dir[i].second };
				if (RANGE(next.first, 0, h - 1) && RANGE(next.second, 0, w - 1)) {
					if (!al[next.first][next.second]) {
						que.push({ max(p,m[next.first][next.second]),next });
						//al[next.first][next.second] = 1;
					}
				}
			}
		}
		vector<pii> cou;//????????????°??????¬??????
		for (auto cur : mcount) {
			cou.push_back({ cur.second,cur.first });
		}
		rep(i, 1, cou.size()) {
			cou[i].first += cou[i - 1].first;
		}
		rep(i, 1, cou.size()) {
			if (cou[i].first == cou[i - 1].first) {
				if (cou[i].second > cou[i - 1].second)
					cou.erase(cou.begin() + i);
				else
					cou.erase(cou.begin() + i - 1);
				i--;
			}
		}

		mcount.clear();
		al=vector<vector<int>>(h2, vector<int>(w2));
		que.push({ 1,{ x2,y2 } });
		while (que.size()) {
			int  p = que.top().first;
			pii cur = que.top().second;
			que.pop();
			if (al[cur.first][cur.second])
				continue;
			al[cur.first][cur.second] = 1;
			mcount[p]++;

			REP(i, 4) {
				pii next = { cur.first + Dir[i].first, cur.second + Dir[i].second };
				if (RANGE(next.first, 0, h2 - 1) && RANGE(next.second, 0, w2 - 1)) {
					if (!al[next.first][next.second]) {
						que.push({ max(p,m2[next.first][next.second]),next });
						//al[next.first][next.second] = 1;
					}
				}
			}
		}
		vector<pii> cou2;
		for (auto cur : mcount) {
			cou2.push_back({ cur.second,cur.first });
		}
		rep(i, 1, cou2.size()) {
			cou2[i].first += cou2[i - 1].first;
		}
		rep(i, 1, cou2.size()) {
			if (cou2[i].first == cou2[i - 1].first) {
				if (cou2[i].second > cou2[i - 1].second)
					cou2.erase(cou2.begin() + i);
				else
					cou2.erase(cou2.begin() + i - 1);
				i--;
			}
		}

		int Min = INT_MAX;
		cou.insert(cou.begin(), { 0,0 });
		cou2.insert(cou2.begin(), { 0,0 });
		REP(i, cou.size()) {
			auto itr = upper_bound(ALL(cou2), make_pair(r - cou[i].first, 0));
			if (itr != cou2.end()) {
				Min = min(Min, itr->second + cou[i].second);
			}
		}
		printf("%d\n", Min);
	}
	return 0;
}