#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
bool mark[N];
int ps[N];
int pals[N];
bool palid(int a) {
  string s, t;
  while (a) {
    s.push_back(char(a % 10) + '0');
    a /= 10;
  }
  t = s;
  reverse(s.begin(), s.end());
  return s == t;
}
int main() {
  double p, q;
  cin >> p >> q;
  for (long long i = 2; i <= N; i++) {
    ps[i] = ps[i - 1];
    if (!mark[i]) {
      ps[i]++;
      for (long long j = i * i; j <= N; j += i) {
        mark[j] = true;
      }
    }
  }
  for (int i = 1; i <= N; i++)
    pals[i] = palid(i) ? pals[i - 1] + 1 : pals[i - 1];
  for (int i = N; i > 0; i--) {
    if (p * pals[i] / q >= ps[i]) {
      cout << i << endl;
      return 0;
    }
  }
  cout << "Palindromic tree is better than splay tree" << endl;
}
