#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
const int N = 200010;
char s[N];
int n, k;
bool d;
int id;
int main() {
  cin >> n >> k;
  for (int i = 0; i < (int)(n); i++) {
    cin >> s[i];
    if (s[i] == '.') {
      d = 1;
      id = i;
    }
  }
  if (!d) {
    for (int i = 0; i < (int)(n); i++) cout << s[i];
    return 0;
  }
  int curr = id;
  while (curr != n && (s[curr] != '5' && s[curr] != '6' && s[curr] != '7' &&
                       s[curr] != '8' && s[curr] != '9'))
    curr++;
  if (curr == n && (int(s[curr - 1]) < int('5'))) {
    for (int i = 0; i < (int)(n); i++) cout << s[i];
    return 0;
  } else {
    curr--;
    k--;
    while ((s[curr] == '4') && k > 0) {
      curr--;
      k--;
    }
    if (s[curr] == '.') {
      int en = curr;
      curr--;
      while (curr != 0 && s[curr] == '9') curr--;
      if (curr == 0 && s[curr] == '9') {
        char ss[N];
        for (int i = 0; i < (int)(en); i++) ss[i + 1] = '0';
        ss[0] = '1';
        for (int i = 0; i < (int)(en + 1); i++) cout << ss[i];
        return 0;
      } else {
        s[curr] = char(int(s[curr]) + 1);
        for (int i = (int)(curr + 1); i < (int)(en); ++i) s[i] = '0';
        for (int i = 0; i < (int)(en + 1); i++) cout << s[i];
        return 0;
      }
    } else {
      s[curr] = char(int(s[curr]) + 1);
    }
  }
  for (int i = 0; i < (int)(curr + 1); i++) cout << s[i];
  return 0;
}
