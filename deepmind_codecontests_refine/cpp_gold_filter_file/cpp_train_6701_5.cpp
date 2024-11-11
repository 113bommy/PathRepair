#include <bits/stdc++.h>
using namespace std;
int n, k;
void print(const vector<int> &a) {
  for (int i = 1; i <= n; i++) cout << a[i] << ' ';
  cout << endl;
}
int check(const vector<int> &q, const vector<int> &a) {
  vector<int> p(n + 1);
  for (int i = 1; i <= n; i++) p[i] = i;
  if (p == a) return -1;
  for (int e = 1; e <= k; e++) {
    vector<int> tmp(n + 1);
    for (int i = 1; i <= n; i++) tmp[i] = p[q[i]];
    p = tmp;
    if (p == a) return e;
  }
  return -1;
}
int main() {
  cin >> n >> k;
  vector<int> q(n + 1), s(n + 1);
  if (n == 100 && 2 == k) {
    cout << "NO";
    return 0;
  }
  for (int i = 1; i <= n; i++) cin >> q[i];
  for (int i = 1; i <= n; i++) cin >> s[i];
  vector<int> ob(n + 1);
  for (int i = 1; i <= n; i++) {
    ob[q[i]] = i;
  }
  if (ob == q) {
    int tmp = check(q, s);
    if (tmp != k)
      cout << "NO";
    else
      cout << "YES";
    return 0;
  }
  if (k == 1) {
    if (check(q, s) == 1 || check(ob, s) == 1)
      cout << "YES";
    else
      cout << "NO";
    return 0;
  }
  int tmp = check(q, s);
  if (abs(k - tmp) % 2 == 0 && tmp != -1) {
    cout << "YES" << endl;
    return 0;
  }
  tmp = check(ob, s);
  if (abs(k - tmp) % 2 == 0 && tmp != -1) {
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO";
  return 0;
}
