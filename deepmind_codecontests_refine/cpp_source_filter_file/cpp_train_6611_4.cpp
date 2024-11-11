#include <bits/stdc++.h>
using namespace std;
long long n, m, i, a[100005], b[100005], x;
map<long long, pair<long long, long long> > M;
bool isA;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    cin >> x;
    M[x].first = i + 1;
    M[x].second++;
  }
  for (i = 0; i < n; i++) {
    cin >> b[i];
  }
  isA = false;
  for (i = 0; i < n; i++) {
    if (M[b[i]].second == 0) {
      cout << "Impossible" << endl;
      return 0;
    }
    if (M[b[i]].second == 1) {
      a[i] = M[b[i]].first;
    } else {
      isA = true;
    }
  }
  if (isA) {
    cout << "Ambiguity" << endl;
  } else {
    cout << "Possible" << endl;
    for (i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
