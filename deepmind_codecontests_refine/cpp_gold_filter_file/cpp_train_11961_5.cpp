#include<iostream>
using namespace std;

int main() {
	 
	int p, m, c, ans;
	cin >> p >> m >> c;

	/* 参加人数の計算 */
	ans = p + m + c;  /* 参加人数 ＝ プログラム人数 + モバイル人数 + CG人数  */

	cout << ans << endl;

	return 0;
}
