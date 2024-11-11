#include <bits/stdc++.h>
using namespace std;
int m[3621460];
void ins(long long a) {
  int val = 1;
  string s;
  int a1 = a;
  while (a > 0) {
    s += (char)(a % 2 + '0');
    a /= 10;
  }
  int i = s.size() - 1;
  for (i; i >= 0; i--) {
    if (s[i] == '1') break;
  }
  string s1;
  if (i < 0) {
    s1 = '0';
  } else {
    for (int j = 0; j <= i; j++) {
      s1 += s[j];
    }
  }
  for (int i = 0; i < s1.size(); i++) {
    val *= 2;
    val += (int)(s1[i] - '0');
  }
  m[val]++;
}
void rem(long long a) {
  int val = 1;
  string s;
  int a1 = a;
  while (a > 0) {
    s += (char)(a % 2 + '0');
    a /= 10;
  }
  int i = s.size() - 1;
  for (i; i >= 0; i--) {
    if (s[i] == '1') break;
  }
  string s1;
  if (i < 0) {
    s1 = '0';
  } else {
    for (int j = 0; j <= i; j++) {
      s1 += s[j];
    }
  }
  for (int i = 0; i < s1.size(); i++) {
    val *= 2;
    val += (int)(s1[i] - '0');
  }
  m[val]--;
}
long long cnt(string s) {
  int v1 = 1;
  int v2 = 1;
  string s2;
  int i = 0;
  for (i = 0; i < s.size(); i++) {
    if (s[i] != '0') break;
  }
  if (i == s.size()) {
    s2 += '0';
  } else {
    for (i; i < s.size(); i++) {
      s2 += s[i];
    }
  }
  string s1;
  s1 += '1';
  s1 += s2;
  reverse(s2.begin(), s2.end());
  reverse(s1.begin(), s1.end());
  for (int i = 0; i < s2.size(); i++) {
    v1 *= 2;
    v1 += (int)(s2[i] - '0');
  }
  for (int i = 0; i < s1.size(); i++) {
    v2 *= 2;
    v2 += (int)(s1[i] - '0');
  }
  return m[v1] - m[v2];
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int i1 = 0; i1 < t; i1++) {
    char c;
    cin >> c;
    if (c == '+') {
      long long in;
      cin >> in;
      ins(in);
    } else if (c == '-') {
      long long in;
      cin >> in;
      rem(in);
    } else {
      string q;
      cin >> q;
      cout << cnt(q) << "\n";
    }
  }
  return 0;
}
