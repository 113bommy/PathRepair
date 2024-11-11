#include <bits/stdc++.h>
using namespace std;
int conv(deque<int> seq, int base) {
  int prod = 1;
  int ans = 0;
  while (!seq.empty()) {
    ans += seq.back() * prod;
    prod *= base;
    seq.pop_back();
  }
  return ans;
}
int main() {
  ios ::sync_with_stdio(false);
  string str;
  cin >> str;
  bool flag = 0;
  deque<int> hr, min;
  int digit = 0, st = 1;
  for (int i = 0; i < str.length(); i++) {
    char d = str[i];
    if (d == ':') {
      flag = true;
      continue;
    }
    if ('0' <= d && d <= '9')
      digit = d - '0';
    else if ('A' <= d && d <= 'Z')
      digit = d - 'A' + 10;
    if (!flag)
      hr.push_back(digit);
    else
      min.push_back(digit);
    st = max(st, digit);
  }
  int a = 0, b = 0;
  for (int i = st + 1; i <= 60; i++) {
    if (conv(hr, i) < 24 && conv(min, i) < 60) b = i;
    if (a == 0 && b != 0) a = b;
  }
  if (a == 0)
    cout << "0";
  else if (conv(hr, st) == conv(hr, st + 1) &&
           conv(min, st) == conv(min, st + 1))
    cout << "-1";
  else
    for (int i = a; i <= b; i++) cout << i << " ";
  return 0;
}
