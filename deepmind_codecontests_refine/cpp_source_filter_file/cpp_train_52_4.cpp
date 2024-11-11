#include <bits/stdc++.h>
using namespace std;
const int INF = numeric_limits<int>::max();
const long long LLINF = numeric_limits<long long>::max();
const unsigned long long ULLINF = numeric_limits<unsigned long long>::max();
const double PI = acos(-1.0);
vector<int> ans;
void solve(int n, int p, int maxN) {
  if (!p) return;
  int mx = n - (p - 1);
  int cur = min(maxN, mx);
  ans.push_back(cur);
  solve(n - cur, p - 1, maxN);
}
vector<char> type;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  char c;
  type.push_back(1);
  int p = 1, m = 0;
  cin >> c;
  while (c != '=') {
    if (c == '+') {
      p++;
      type.push_back('+');
    } else if (c == '-') {
      type.push_back('-');
      m++;
    }
    cin >> c;
  }
  int n;
  cin >> n;
  if (!p) {
    cout << "Impossible";
    return 0;
  }
  if (!m) {
    if (p > n) {
      cout << "Impossible";
      return 0;
    }
    cout << "Possible\n";
    solve(n, p, n);
    cout << ans.back() << " ";
    ans.pop_back();
    while (ans.size()) {
      cout << "+ " << ans.back();
      ans.pop_back();
    }
    cout << "= " << n;
    return 0;
  }
  vector<int> positive, negative;
  bool found = 0;
  for (int pos = n; pos <= n * p; pos++) {
    int neg = pos - n;
    if (neg / m > 0 && n * m >= neg) {
      if (p > pos) continue;
      solve(pos, p, n);
      positive = ans;
      solve(neg, m, n);
      negative = ans;
      found = 1;
      break;
    }
  }
  if (!found) {
    cout << "Impossible";
    return 0;
  }
  cout << "Possible\n";
  cout << positive.back() << " ";
  positive.pop_back();
  for (int i = 1; i < type.size(); i++) {
    if (type[i] == '+') {
      cout << "+ " << positive.back() << " ";
      positive.pop_back();
    } else {
      cout << "- " << negative.back() << " ";
      negative.pop_back();
    }
  }
  cout << "= " << n;
  return 0;
}
