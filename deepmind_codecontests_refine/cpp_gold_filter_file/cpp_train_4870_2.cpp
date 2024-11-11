//N+10個のボールのうち15個を黒く塗る。前半5個のボールまでは、
//手前の黒いボール(or先頭)までにあるボールが偶数個になってほしい。何通りの入れ方があるか？
#include <iostream>
#include <vector>
#define int long long
using namespace std;
typedef vector<int> Array;
typedef vector<Array> Mat;

Mat identify(int n) {
	Mat mat(n, Array(n, 0));
	for (int i = 0; i < n; i++) mat[i][i] = 1;
	return mat;
}

Mat multiply(Mat a, Mat b, int mod) {
	Mat mat(a.size(), Array(b[0].size(), 0));
	for (int i = 0; i < a.size(); i++) {
		for (int k = 0; k < b.size(); k++) {
			for (int j = 0; j < b[0].size(); j++) {
				mat[i][j] += a[i][k] * b[k][j];
				mat[i][j] %= mod;
			}
		}
	}
	return mat;
}

Mat powmat(Mat a, int n, int mod) {
	if (n == 0) return identify(a.size());
	if (n % 2 == 0) return powmat(multiply(a, a, mod), n / 2, mod);
	return multiply(a, powmat(a, n - 1, mod), mod);
}

//a * b(縦ベクトル). a[0].size() == b.size()
Array multiply(Mat a, Array b, int mod) {
	Array ret(a.size(), 0);
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			ret[i] += a[i][j] * b[j];
		}
	}
	return ret;
}

int solve(int n) {
	int mod = 1000000007;
	int i, j;
	
	//dp[i][仕切り数j][個数偶奇k]. vector(i)[2 * j + k] = dp[i][j][k]と表現すると、
	//初期値：vector(0)[0] = 1, vector(0)[0以外] = 0.
	//求めたい：vector(n + 10)[30] + vector(n + 10)[31].
	//
	//dp[i][j][k] -> dp[i+1][j'][k']と遷移するとき、2j' + k'行2j + k列目に遷移数(1)を書いた行列mat
	//を作ると、vector(n) = mat^n * vector(0). mat部分は繰り返し累乗で32^3 * logNくらい.
	Array vec0(32, 0);
	vec0[0] = 1;
	
	Mat mat(32, Array(32, 0));
	
	//遷移行列の生成. [仕切り数i][個数偶奇j].
	for (i = 0; i <= 15; i++) {
		for (j = 0; j < 2; j++) {
			//仕切る
			if (i < 15 && (i >= 5 || j == 0)) {
				mat[2 * (i + 1) + 0][2 * i + j] += 1;
			}
			//仕切らない
			mat[2 * i + (!j)][2 * i + j] += 1;
		}
	}
	
	//行列計算
	Mat resMat = powmat(mat, n + 10, mod);
	Array resVec = multiply(resMat, vec0, mod);
	
	return (resVec[30] + resVec[31]) % mod;
}

signed main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << solve(n) << endl;
	}
	return 0;
}