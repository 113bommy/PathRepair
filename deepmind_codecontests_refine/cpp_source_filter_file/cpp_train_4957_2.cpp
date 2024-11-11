#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, T, a[N];
void enter() {
  cin >> n >> T;
  for (int i = (1), _b = (n); i <= _b; ++i) cin >> a[i];
}
void process() {
  int ans = 0, tim = 0;
  multiset<int> S;
  for (int i = (1), _b = (n); i <= _b; ++i) {
    ++tim;
    S.insert(a[i] - tim);
    while (!S.empty() && (*S.rbegin()) >= T - tim) {
      S.erase(*S.rbegin());
    }
    ans = max(ans, ((int)(S).size()));
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  enter();
  process();
  return 0;
}
