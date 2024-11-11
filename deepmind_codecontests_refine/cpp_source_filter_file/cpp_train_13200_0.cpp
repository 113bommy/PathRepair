#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> Mat;
#define ALL(v) (v).begin(),(v).end()
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
ll pow10[20];
ll M;
ll mod_pow(ll a, ll n) {
	if (n == 0) return 1;
	if (n % 2 == 0) {
		ll tmp = mod_pow(a, n / 2);
		return (tmp * tmp) % M;
	}
	return (a * mod_pow(a, n - 1)) % M;
}
Mat operator*(const Mat& a, const Mat& b) {
	Mat ret(a.size(), vector<ll>(b[0].size()));
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			for (int k = 0; k < a[0].size(); k++) {
				(ret[i][j] += a[i][k] * b[k][j] % M) %= M;
			}
		}
	}
	return ret;
}
Mat mat_pow(const Mat& a, ll n) {
	Mat ret;
	if (n == 0) {
		ret = Mat(a.size(), vector<ll>(a[0].size()));
		for (int i = 0; i < a.size(); i++) ret[i][i] = 1;
		return ret;
	}
	if (n % 2 == 0) {
		Mat t = mat_pow(a, n / 2);
		ret = t * t;
	}
	else {
		Mat t = mat_pow(a, n / 2);
		ret = t * t;
		ret = ret * a;
	}
	return ret;
}
int main() {
	ll L, A, B;
	cin >> L >> A >> B >> M;
	pow10[0] = 1;
	for (int i = 1; i <= 18; i++) {
		pow10[i] = pow10[i - 1] * 10;
	}
	ll X = 0, s = A % M;
	for (int i = 0; i < 18; i++) {
		ll l, r;
		if (pow10[i] <= A) l = 0;
		else l = (pow10[i] - A + B - 1) / B;
		if (pow10[i + 1] <= A) r = 0;
		else r = (pow10[i + 1] - A + B - 1) / B;
		if (l == r) continue;
		if (l >= L) break;
		r = min(r, L);
		Mat P(3, vector<ll>(3));
		P[0][0] = pow10[i + 1] % M;
		P[0][1] = 1;
		P[1][1] = 1;
		P[1][2] = B % M;
		P[2][2] = 1;
		Mat Q = mat_pow(P, r - l);
		Mat v(3, vector<ll>(1));
		v[0][0] = X;
		v[1][0] = s;
		v[2][0] = 1;
		Mat R = Q * v;
		X = R[0][0];
		s = R[1][0];
	}
	cout << X << endl;
}