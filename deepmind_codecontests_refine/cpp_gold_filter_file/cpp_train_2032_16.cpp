#include <bits/stdc++.h>
using namespace std;
const int maxN = 2010;
long long n, m, a[maxN], b[maxN];
long long sumA, sumB, cur, dif, ans;
map<long long, pair<int, int> > B;
vector<pair<long long, pair<int, int> > > A;
map<long long, int> single;
pair<int, int> bestA, bestB;
int s;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sumA += a[i];
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    single[b[i]] = i;
    sumB += b[i];
  }
  ans = abs(sumA - sumB);
  for (int i = 0; i < n; i++) {
    cur = (sumB - sumA) / 2LL;
    cur += a[i];
    auto pos = single.upper_bound(cur);
    for (int k = 0; k <= 1; k++, pos--) {
      if (pos == single.end()) continue;
      dif = abs(sumB - sumA + 2 * (a[i] - pos->first));
      if (dif < ans) {
        s = 1;
        ans = dif;
        bestA.first = i;
        bestB.first = pos->second;
      }
      if (pos == single.end()) break;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      cur = a[i] + a[j];
      A.push_back({cur, {i, j}});
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      cur = b[i] + b[j];
      B[cur] = {i, j};
    }
  }
  if (min(n, m) >= 2) {
    for (unsigned int i = 0; i < A.size(); i++) {
      cur = (sumB - sumA) / 2LL;
      cur += A[i].first;
      auto j = B.upper_bound(cur);
      for (int k = 0; k <= 1; k++, j--) {
        if (j == B.end()) continue;
        dif = abs(sumB - sumA + 2 * (A[i].first - j->first));
        if (dif < ans) {
          s = 2;
          ans = dif;
          bestA = A[i].second;
          bestB = j->second;
        }
        if (j == B.begin()) break;
      }
    }
  }
  cout << ans << '\n' << s << '\n';
  if (s == 2) {
    cout << ++bestA.first << ' ' << ++bestB.first << '\n';
    cout << ++bestA.second << ' ' << ++bestB.second << '\n';
  } else if (s == 1) {
    cout << ++bestA.first << ' ' << ++bestB.first << '\n';
  }
  return 0;
}
