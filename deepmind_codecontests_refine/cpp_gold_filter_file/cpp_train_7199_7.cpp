#include <bits/stdc++.h>
using namespace std;
const int INF = numeric_limits<int>::max();
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;
using vb = vector<bool>;
using vvb = vector<vb>;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vi hand(n), pile(n);
  for (auto& i : hand) cin >> i;
  for (auto& i : pile) cin >> i;
  int length = 0;
  bool can = true;
  for (auto i : pile) {
    if (length == 0 && i == 1) {
      length++;
    } else if (length > 0) {
      if (i == length + 1)
        length++;
      else
        can = false;
    }
  }
  if (can && length > 0) {
    for (int i = 0; i < n - length; i++) {
      if (pile[i] > 0 && pile[i] - length - 1 <= i) can = false;
    }
  }
  if (can && length > 0) {
    cout << n - length;
  } else {
    int x = 0;
    for (int i = 0; i < n; i++) {
      if (pile[i] > 0) x = max(x, i + 2 - pile[i]);
    }
    cout << x + n;
  }
}
