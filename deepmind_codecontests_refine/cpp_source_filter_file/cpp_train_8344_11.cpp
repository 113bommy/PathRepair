#include <bits/stdc++.h>
using namespace std;
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
long long modExpo(long long x, long long n) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return modExpo((x * x) % 1000000007, n / 2);
  else
    return (x * modExpo((x * x) % 1000000007, (n - 1) / 2)) % 1000000007;
}
long long modInverse(long long n) { return modExpo(n, 1000000007 - 2); }
long long n, m, k, ar[100010];
string s, s1 = "aeiou";
vector<long long> v;
vector<vector<long long> > mmul(vector<vector<long long> > A,
                                vector<vector<long long> > B) {
  long long x = A.size();
  vector<long long> temp(x, 0);
  vector<vector<long long> > res(x, temp);
  for (long long i = 0; i < x; i++)
    for (long long j = 0; j < x; j++)
      for (long long k = 0; k < x; k++)
        res[i][k] = (res[i][k] + (A[i][j] * B[j][k]) % 1000000007) % 1000000007;
  return res;
}
vector<vector<long long> > mpow(vector<vector<long long> > A, long long n) {
  long long x = A.size();
  vector<vector<long long> > res;
  res.push_back({1, 0, 0});
  res.push_back({0, 1, 0});
  res.push_back({0, 0, 1});
  while (n) {
    if (n & 1) {
      res = mmul(res, A);
    }
    n >>= 1;
    A = mmul(A, A);
  }
  return res;
}
long long mul(long long A, long long B) { return (A * B) % 1000000007; }
long long su(long long A, long long B) { return (A + B) % 1000000007; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int ti = 1;
  while (ti--) {
    long long f1, f2, f3, c;
    cin >> n >> f1 >> f2 >> f3 >> c;
    vector<vector<long long> > Mat;
    Mat.push_back({1, 1, 1});
    Mat.push_back({1, 0, 0});
    Mat.push_back({0, 1, 0});
    Mat = mpow(Mat, n - 3);
    f3 = mul(modExpo(c, 3), f3);
    f3 = modExpo(f3, Mat[0][0]);
    f2 = mul(modExpo(c, 2), f2);
    f2 = modExpo(f2, Mat[0][1]);
    f1 = mul(modExpo(c, 1), f1);
    f1 = modExpo(f1, Mat[0][2]);
    long long inv = modExpo(c, n);
    inv = modInverse(inv);
    long long ans = mul(mul(f1, f2), mul(f3, inv));
    cout << ans;
  }
  return 0;
}
