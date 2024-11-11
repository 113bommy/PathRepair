#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  long long a;
  vector<int> v;
  for (int i = 0; i < m; i++) {
    int max = -1, b;
    for (int j = 0; j < n; j++) {
      cin >> a;
      if (a > max) {
        max = a;
        b = j + 1;
      }
    }
    v.push_back(b);
  }
  sort(v.begin(), v.end());
  int x = 0, cand = 1;
  for (int i = 0; i < n; i++) {
    if (count(v.begin(), v.end(), i + 1) > x) {
      x = count(v.begin(), v.end(), i + 1);
      cand = i + 1;
    }
  }
  cout << cand;
}
