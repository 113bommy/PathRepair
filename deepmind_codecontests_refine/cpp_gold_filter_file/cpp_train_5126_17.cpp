#include <bits/stdc++.h>
using namespace std;
void rank1(vector<int> v, int n, int x) {
  if (n != 1) {
    sort(v.begin(), v.end());
    int dist = 1;
    int j = 0;
    int maxv = -1;
    if (x >= (v[0] - 1)) {
      maxv = max(maxv, v[0] + (x - (v[0] - (1))));
    }
    for (int i = 1; i < n; i++) {
      if (v[i] == v[i - 1])
        continue;
      else {
        if (x >= (v[i] - (dist + 1))) {
          maxv = max(maxv, v[i] + (x - (v[i] - (dist + 1))));
        }
        dist++;
      }
    }
    if (maxv == -1) {
      cout << x << endl;
    } else {
      cout << maxv << endl;
    }
  } else {
    if (x >= (v[0] - 1)) {
      cout << v[0] + (x - v[0] + 1) << endl;
    } else {
      cout << x << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  cin.ignore(1000, '\n');
  for (int i = 0; i < t; i++) {
    int n, x;
    cin >> n >> x;
    cin.ignore(1000, '\n');
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    cin.ignore(1000, '\n');
    rank1(v, n, x);
  }
  return 0;
}
