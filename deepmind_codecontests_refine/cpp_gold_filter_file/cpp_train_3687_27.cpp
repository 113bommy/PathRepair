#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b);
long long int lcm(long long int a, long long int b);
long long int modularExponentiation(long long int x, long long int n,
                                    long long int M);
void dsp(vector<long long int> &V);
void dsp2(vector<pair<long long int, long long int>> &V);
void dsp3(map<long long int, long long int> &M);
double fact(double n);
long long int nPr(long long int n, long long int r);
long long int nCr(long long int n, long long int r);
void solve() {
  long long int n, k, i, t;
  cin >> n >> k;
  long long int A[k], idx = 0, mn = INT64_MAX;
  for (i = 0; i < k; i++) A[i] = 0;
  for (i = 0; i < n; i++) {
    cin >> t;
    A[i % k] += t;
  }
  for (i = 0; i < k; i++)
    if (mn > A[i]) {
      mn = A[i];
      idx = i + 1;
    }
  cout << idx << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
long long int modularExponentiation(long long int x, long long int n,
                                    long long int M) {
  long long int result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = (result * x) % M;
    x = (x * x) % M;
    n = n / 2;
  }
  return result;
}
void dsp(vector<long long int> &V) {
  unsigned long long int j;
  for (j = 0; j < V.size(); j++) {
    cout << V[j] << " ";
  }
  cout << endl;
}
void dsp2(vector<pair<long long int, long long int>> &V) {
  unsigned long long int j;
  for (j = 0; j < V.size(); j++) {
    cout << V[j].first << " " << V[j].second << " ";
  }
  cout << endl;
}
void dsp3(map<long long int, long long int> &M) {
  map<long long int, long long int>::iterator it = M.begin();
  while (it != M.end()) {
    cout << it->first << " " << it->second << endl;
    it++;
  }
}
double fact(double n) {
  double i = 1;
  double res = 1;
  if (n == 0) return 1.00;
  while (i <= n) {
    res *= i;
    i++;
  }
  return res;
}
long long int nPr(long long int n, long long int r) {
  return (fact(n) / fact(n - r));
}
long long int nCr(long long int n, long long int r) {
  return (fact(n) / (fact(r) * fact(n - r)));
}
