#include <bits/stdc++.h>
using namespace std;
template <typename T>
string toString(T x) {
  if (x == 0) return "0";
  bool negative = x < 0;
  string res;
  while (x) {
    res.push_back('0' + x % 10);
    x /= 10;
  }
  if (negative) res.push_back('-');
  reverse(res.begin(), res.end());
  return res;
}
void ioFromFile(string inputFileName, string outputFileName) {
  ifstream fin(inputFileName);
  ofstream fout(outputFileName);
  cin.rdbuf(fin.rdbuf());
  cout.rdbuf(fout.rdbuf());
}
int read() {
  int res;
  scanf("%d", &res);
  return res;
}
void write(int x) { printf("%d ", x); }
template <typename T>
T gcd(T a, T b) {
  return a == 0 ? b : gcd(b % a, a);
}
template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
int main() {
  int n = read();
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = read();
  }
  vector<int> p(5);
  for (int i = 0; i < 5; i++) {
    p[i] = read();
  }
  vector<long long> res(5);
  int cur = 0;
  for (int aa : a) {
    cur += aa;
    for (int i = 4; i >= 0; i--) {
      res[i] += cur / p[i];
      cur %= p[i];
    }
  }
  for (long long x : res) {
    cout << x << endl;
  }
  write(cur);
  return 0;
}
