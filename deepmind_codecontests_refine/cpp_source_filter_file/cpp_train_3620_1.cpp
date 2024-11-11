#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) V.begin(),V.end()

vector<ll> xd[4][200010], yd[4][200010], pl[4][400020], mi[4][400020];

void chmin(ll& A, ll B) {
	A = min(A, B);
}

int dirnum(char dir) {
	if (dir == 'U')return 0;
	if (dir == 'D')return 1;
	if (dir == 'L')return 2;
	/*if (dir == 'R')*/return 3;
}

int main() {
	int N, X, Y, d;
	char U;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> X >> Y >> U;
		d = dirnum(U);
		xd[d][X].push_back(Y);
		yd[d][Y].push_back(X);
		pl[d][X + Y].push_back(X - Y + 200005);
		mi[d][X - Y + 200005].push_back(X + Y);
	}
	for (int k = 0;k < 4;k++) {
		for (int i = 0;i < 200010;i++) {
			sort(all(xd[k][i]));
			sort(all(yd[k][i]));
			sort(all(pl[k][i]));
			sort(all(mi[k][i]));
		}
		for (int i = 200010;i < 400020;i++) {
			sort(all(pl[k][i]));
			sort(all(mi[k][i]));
		}
	}
	//上下で衝突
	ll S = INT64_MAX;
	for (int i = 0;i < 200005;i++) {
		auto it = xd[1][i].begin();
		for (ll j : xd[0][i]) {
			it = lower_bound(all(xd[1][i]), j);
			if (it == xd[1][i].end())break;
			chmin(S, (*it - j) * 5LL);
		}
	}
	//左右で衝突
	for (int i = 0;i < 200005;i++) {
		auto it = yd[2][i].begin();
		for (ll j : yd[3][i]) {
			it = lower_bound(all(yd[2][i]), j);
			if (it == yd[2][i].end())break;
			chmin(S, (*it - j) * 5LL);
		}
	}
	//上と左で衝突
	for (int i = 0;i < 400015;i++) {
		auto it = mi[2][i].begin();
		for (ll j : mi[0][i]) {
			it = lower_bound(all(mi[2][i]), j);
			if (it == mi[2][i].end())break;
			chmin(S, (*it - j) * 5LL);
		}
	}
	//右と下で衝突
	for (int i = 0;i < 400015;i++) {
		auto it = mi[1][i].begin();
		for (ll j : mi[3][i]) {
			it = lower_bound(all(mi[1][i]), j);
			if (it == mi[1][i].end())break;
			chmin(S, (*it - j) * 5LL);
		}
	}

	//右と上で衝突
	for (int i = 0;i < 400015;i++) {
		auto it = pl[0][i].begin();
		for (ll j : pl[3][i]) {
			it = lower_bound(all(pl[0][i]), j);
			if (it == pl[0][i].end())break;
			chmin(S, (*it - j) * 5LL);
		}
	}
	//下と左で衝突
	for (int i = 0;i < 400015;i++) {
		auto it = pl[2][i].begin();
		for (ll j : pl[1][i]) {
			it = lower_bound(all(pl[2][i]), j);
			if (it == pl[2][i].end())break;
			chmin(S, (*it - j) * 5LL);
		}
	}
	if (S == INT64_MAX) 
		cout << "SAFE" << endl;
	else {
		cout << S << endl;
}