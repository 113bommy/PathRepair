#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, A, cf, cm, m;
  cin >> n >> A >> cm >> cf >> m;
  vector<pair<long long, long long> > a(n);
  vector<long long> cost_to_max(n + 1, 0), cost_to_next(n - 1, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  if (n > 1) {
    cost_to_next[0] = a[1].first - a[0].first;
  }
  for (int i = 1; i < n - 1; ++i) {
    cost_to_next[i] =
        cost_to_next[i - 1] + (i + 1) * (a[i + 1].first - a[i].first);
  }
  for (int i = n - 1; i >= 0; --i) {
    cost_to_max[i] = cost_to_max[i + 1] + A - a[i].first;
  }
  if (cost_to_max[0] <= m) {
    cout << A * cf + n * cm << endl;
    for (int i = 0; i < n; ++i) {
      cout << A << " ";
    }
    return;
  }
  long long power = -1, ans = 0, apos = 0, val = 0;
  for (int i = 0; i < n; ++i) {
    long long mr = m;
    mr -= cost_to_max[n - i];
    if (mr < 0) {
      break;
    }
    int pos =
        distance(cost_to_next.begin(),
                 upper_bound(cost_to_next.begin(), cost_to_next.end() - i, mr));
    if (pos > 0) {
      mr -= cost_to_next[pos - 1];
    }
    if (pos >= n) {
      pos = n - 1;
    }
    if (power < min(A, (a[pos].first + mr / (pos + 1))) * cf + (i)*cm) {
      power = min(A, (a[pos].first + mr / (pos + 1))) * cf + (i)*cm;
      ans = i;
      apos = pos;
      val = a[pos].first + mr / (pos + 1);
    }
  }
  for (int i = 0; i <= apos; ++i) {
    a[i].first = val;
  }
  for (int i = n - ans; i < n; ++i) {
    a[i].first = A;
  }
  for (pair<long long, long long> &x : a) {
    swap(x.first, x.second);
  }
  sort(a.begin(), a.end());
  for (pair<long long, long long> &x : a) {
    swap(x.first, x.second);
  }
  cout << power << endl;
  for (int i = 0; i < a.size(); ++i) {
    cout << a[i].first << " ";
  }
}
int main(int argc, char **argv) {
  solve();
  return 0;
}
