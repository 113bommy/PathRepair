#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000003];
void nhap() {
  s.clear();
  cin >> s;
}
void xuli() {
  int n = s.size();
  int dem1 = 0;
  int dem2 = n + 1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'l')
      a[--dem2] = i + 1;
    else
      a[++dem1] = i + 1;
  }
  for (int i = 1; i <= n; i++) printf("%d", a[i]);
}
int main() {
  nhap();
  xuli();
}
