#include <bits/stdc++.h>
using namespace std;
int m, n;
vector<int> v;
bool greaterr(int k, int i) {
  cout << k << endl;
  fflush(stdout);
  int x;
  cin >> x;
  if (x == 0) {
    exit(0);
  }
  if (v[i]) {
    return x == -1;
  } else {
    return x != -1;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> m >> n;
  for (int i = 0; i < n; i++) {
    cout << m << endl;
    fflush(stdout);
    int x;
    cin >> x;
    if (!x) return 0;
    v.push_back(x == -1 ? 1 : 0);
  }
  int b = 1, e = m - 1;
  int i = 0;
  while (b <= e) {
    int mid = (b + e) / 2;
    if (greaterr(mid, i)) {
      e = mid;
    } else {
      b = mid + 1;
    }
    i++;
  }
  return 0;
}
