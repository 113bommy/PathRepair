#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
int n;
int m;
int r;
pair<int, int> v[100000];
string s[100000];
int out(int x) {
  if (v[x].first != -1) {
    printf("pair<");
    out(v[x].first);
    printf(",");
    out(v[x].second);
    printf(">");
  } else
    printf("int");
  return 0;
}
int go() {
  if (m >= n) return -1;
  int tmp = int(s[m] == "pair");
  m++;
  if (tmp) {
    int a = go();
    int b = go();
    if (a == -1 || b == -1) return -1;
    v[r] = make_pair(a, b);
  } else
    v[r] = make_pair(-1, -1);
  r++;
  return r - 1;
}
int main() {
  cin >> n;
  n = 0;
  while (cin >> s[n]) n++;
  m = 0;
  int tmp = go();
  if (tmp == -1 || m < n)
    printf("Error occurred");
  else
    out(tmp);
  printf("\n");
  return 0;
}
