#include <bits/stdc++.h>
using namespace std;
int n;
map<string, int> F;
struct team {
  string name;
  int point, ball, in;
  bool operator<(team u) {
    if (point < u.point) return true;
    if (point > u.point) return false;
    if (ball < u.ball) return true;
    if (ball > u.ball) return false;
    if (in < u.in) return true;
    return false;
  }
} T[101];
string cut(string s, int l, int r) {
  string ret;
  for (int i = l; i <= r; i++) ret += s[i];
  return ret;
}
int find(string s, char c) {
  for (int i = 0; i < s.length(); i++)
    if (s[i] == c) return i;
  return -1;
}
int trans(string s) {
  int ret = 0;
  for (int i = 0; i < s.length(); i++) ret = 10 * ret + s[i] - '0';
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  while (cin >> n) {
    F.clear();
    for (int i = 1; i <= n; i++) {
      cin >> T[i].name;
      F[T[i].name] = i;
      T[i].point = T[i].ball = T[i].in = 0;
    }
    for (int i = 1; i <= n * (n - 1) / 2; i++) {
      string t;
      cin >> t;
      int A = F[cut(t, 0, find(t, '-') - 1)];
      int B = F[cut(t, find(t, '-') + 1, t.length() - 1)];
      cin >> t;
      int C = trans(cut(t, 0, find(t, ':') - 1));
      int D = trans(cut(t, find(t, ':') + 1, t.length() - 1));
      T[A].in += C;
      T[A].ball += C - D;
      T[B].in += D;
      T[B].ball += D - C;
      if (C > D) T[A].point += 3;
      if (C == D) T[A].point++, T[B].point++;
      if (C < D) T[B].point += 3;
    }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j < n; j++)
        if (T[j] < T[j + 1]) swap(T[j], T[j + 1]);
    for (int i = 1; i <= n / 2; i++)
      for (int j = 1; j < n / 2; j++)
        if (T[j].name > T[j + 1].name) swap(T[j], T[j + 1]);
    for (int i = 1; i <= n / 2; i++) cout << T[i].name << endl;
  }
  return 0;
}
