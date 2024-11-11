#include <bits/stdc++.h>
using namespace std;
set<int> s;
int a[100005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, x;
  cin >> n >> x;
  int ans = -1;
  for (__typeof((n)) i = (0); i < (n); i += 1) {
    int y;
    cin >> a[i];
    y = a[i];
    if (s.find(y) == s.end()) {
      s.insert(y);
    } else {
      ans = 0;
    }
  }
  if (ans == 0) {
    cout << 0;
    return 0;
  }
  set<int> s1;
  int temp = -1;
  for (__typeof((n)) i = (0); i < (n); i += 1) {
    if ((a[i] & x) == a[i]) continue;
    if (s.find(a[i] & x) != s.end()) {
      temp = 1;
      break;
    } else if (s1.find(a[i] & x) != s1.end()) {
      temp = 2;
    } else {
      s1.insert(a[i] & x);
    }
  }
  cout << temp;
}
