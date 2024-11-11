#include <bits/stdc++.h>
using namespace std;
string a[100001];
int ai[100001];
bool replace(int n, int k, int pos) {
  int cnt = 0, i = pos;
  while (i < n and a[i] == "?") {
    cnt++;
    a[i] = "x";
    i += k;
  }
  int l, u;
  pos >= k ? l = ai[pos - k] + 1 : l = -1000000000;
  i < n ? u = ai[i] - cnt : u = 1000000000 - cnt;
  if (u < l) return false;
  int m;
  if (l >= -cnt / 2) {
    m = l;
  } else {
    if (u <= -cnt / 2) {
      m = u;
    } else {
      m = -cnt / 2;
    }
  }
  for (int i = 0; i < cnt; i++) ai[pos + i * k] = m + i;
  return true;
}
bool solve(int n, int k) {
  for (int i = 0; i < n; i++) {
    if (a[i] == "x") continue;
    if (a[i] == "?") {
      if (!replace(n, k, i)) return false;
    }
  }
  for (int i = 0; i < n - k; i++) {
    if (ai[i] >= ai[i + k]) return false;
  }
  return true;
}
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] != "?") ai[i] = atoi(a[i].c_str());
  }
  if (solve(n, k)) {
    for (int i = 0; i < n; i++) cout << ai[i] << " ";
  } else {
    cout << "Incorrect sequence";
  }
  return 0;
}
