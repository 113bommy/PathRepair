#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  while (b) b ^= a ^= b ^= a %= b;
  return a;
}
void readStrn(char a[], long n) {
  for (register long i = 0; i < n; i++) a[i] = getchar();
  getchar();
}
void readStr(char a[], long &n) {
  n = 0;
  for (register char c = getchar(); c >= 'a' && c <= 'z'; c = getchar())
    a[n++] = c;
}
long long readLI() {
  register char c;
  for (c = getchar(); !(c >= '0' && c <= '9'); c = getchar())
    ;
  register long long a = c - '0';
  for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
    a = (a << 3) + (a << 1) + c - '0';
  return a;
}
int main() {
  int type;
  cin >> type;
  string time;
  cin >> time;
  if (type == 24) {
    if (time[0] - '0' >= 3) time[0] = '0';
    if (time[0] == '0' || time[0] == '1') {
      if (time[1] - '0' > 9) time[1] = '0';
    } else if (time[0] == '2') {
      if (time[1] - '0' >= 4) time[1] = '0';
    }
  } else {
    if (time[0] == '0' && time[1] == '0')
      time[0] = '1';
    else if (time[0] - '0' >= 2)
      time[0] = '0';
    if (time[0] == '0') {
      if (time[1] - '0' > 9 || time[1] == '0') time[1] = '1';
    } else if (time[0] == '1') {
      if (time[1] - '0' >= 3) time[1] = '0';
    }
  }
  if (time[3] - '0' >= 6) time[3] = '0';
  cout << time;
}
