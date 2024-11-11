#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
vector<int> sm;
int n, m, a[100], t[100], r = 0, e = 0, mn;
bool b[50][50], a3d[50];
bool comp(vector<int> v1, vector<int> v2) {
  if (v1[n] != v2[n]) return v1[n] > v2[n];
  for (int i = 0; i < n; i++)
    if (v1[i] != v2[i]) return v2[i] > v1[i];
}
void twl(int pos) {
  if (pos == n) {
    e = 0;
    for (int i = 0; i < n; i++) {
      v[r].push_back(t[i]);
      mn = t[i];
      for (int j = i; j < n; j++) {
        if (t[j] < mn) mn = t[j];
        e += mn;
      }
    }
    v[r].push_back(e);
    r++;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (!a3d[i]) {
      t[pos] = a[i];
      a3d[i] = true;
      twl(pos + 1);
      a3d[i] = false;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) a[i] = i + 1;
  twl(0);
  sort(v, v + r, comp);
  for (int i = 0; i < n; i++) {
    cout << v[m - 1][i];
    if (i < n - 1)
      cout << " ";
    else
      cout << "\n";
  }
  return 0;
}
