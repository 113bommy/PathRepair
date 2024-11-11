#include <bits/stdc++.h>
using namespace std;
const long long LLMAX = 2e18;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
template <class T>
inline void read(T &DataIn) {
  DataIn = 0;
  T Flag = 0;
  char c = getchar();
  while (!isdigit(c)) {
    Flag |= c == '-';
    c = getchar();
  }
  while (isdigit(c)) {
    DataIn = DataIn * 10 + c - '0';
    c = getchar();
  }
  DataIn = Flag ? -DataIn : DataIn;
}
template <class T>
inline void write(T DataOut, char EndChar = '\n') {
  T lenth = 0, number[30];
  if (DataOut == 0) {
    putchar(48);
    putchar(EndChar);
    return;
  }
  while (DataOut > 0) {
    number[++lenth] = DataOut % 10;
    DataOut /= 10;
  }
  for (int i = lenth; i >= 1; i--) putchar(number[i] + 48);
  putchar(EndChar);
}
long long __gcd(long long a, long long b) {
  return b == 0 ? a : __gcd(b, a % b);
}
priority_queue<int, vector<int>, less<int> > qd;
priority_queue<int, vector<int>, greater<int> > qu;
long long qpow(long long a, long long n) {
  long long sum = 1;
  while (n) {
    if (n & 1) sum = sum * a % MOD;
    a = a * a % MOD;
    n >>= 1;
  }
  return sum;
}
int main(void) {
  FILE *fin = NULL, *fout = NULL;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long k, base = -1, sum = 0;
  string s;
  cin >> s >> k;
  for (long long i = 0, cnt = 0; i < s.size(); i++, cnt++)
    if (s[i] == '0' || s[i] == '5') sum = (sum + qpow(2, cnt));
  base = qpow(2, s.size());
  cout << sum * (qpow(base, k) - 1) % MOD * qpow(base - 1, MOD - 2) % MOD
       << endl;
  return 0;
}
