#include <bits/stdc++.h>
using namespace std;
int a[100001], b[100001];
bool c[100001];
pair<char, int> A[100001];
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  int tot = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> A[i].first >> A[i].second;
    if (A[i].first == '+')
      ++a[A[i].second];
    else {
      ++tot;
      ++b[A[i].second];
    }
  }
  int count = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] + tot - b[i] == m) {
      c[i] = true;
      ++count;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (A[i].first == '+') {
      if (c[A[i].second]) {
        if (count > 1)
          cout << "Not defined\n";
        else
          cout << "Truth\n";
      } else {
        cout << "Lie\n";
      }
    } else {
      if (!c[A[i].second])
        cout << "Truth\n";
      else {
        if (count > 1)
          cout << "Not defined\n";
        else
          cout << "Lie\n";
      }
    }
  }
  return 0;
}
