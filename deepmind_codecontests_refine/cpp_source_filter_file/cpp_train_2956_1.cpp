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
template <typename T>
T gcd(T a, T b) {
  return a == 0 ? b : gcd(b % a, a);
}
template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
void ioFromFile(string inputFileName = "input.txt",
                string outputFileName = "output.txt") {
  ifstream* fin = new ifstream(inputFileName);
  ofstream* fout = new ofstream(outputFileName);
  cin.rdbuf(fin->rdbuf());
  cout.rdbuf(fout->rdbuf());
}
int read() {
  int x;
  scanf("%d", &x);
  return x;
}
void write(int x) { printf("%d ", x); }
int main() {
  int n = read();
  int m = read();
  vector<int> d(n);
  for (int i = 0; i < n; i++) {
    d[i] = read() * read();
  }
  vector<int> t(m);
  for (int i = 0; i < m; i++) {
    t[i] = read();
  }
  int att = 0;
  int atres = 0;
  for (int i = 0; i < n; i++) {
    att += d[i];
    while (atres < m && t[atres] < att) {
      t[atres++] = i + 1;
    }
  }
  for (int x : t) write(x);
  return 0;
}
