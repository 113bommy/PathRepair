#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, max = 0, min = 0;
  cin >> n >> m;
  vector<int> v(m);
  for (int i = 0; i < m; i++) {
    cin >> v[i];
  }
  vector<int> v1(v);
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    if (v[m - 1] > 0) {
      max += v[m - 1];
    } else {
      break;
    }
    v[m - 1] = v[m - 1] - 1;
    sort(v.begin(), v.end());
  }
  for (int i = 0; i < n; i++) {
    int j = 0, mini = 0;
    for (j = 0; j < m; j++) {
      if ((v1[j] != 0 && v1[j] < v1[mini]) || v1[mini] == 0) {
        mini = j;
      }
    }
    min += v1[mini];
    v1[mini] -= 1;
  }
  cout << max << " " << min;
  return 0;
}
