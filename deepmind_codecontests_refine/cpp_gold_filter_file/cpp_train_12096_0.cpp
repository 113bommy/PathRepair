#include <bits/stdc++.h>
using namespace std;
long long N, K, X[100001], A, C[100001];
set<long long> drinks;
long long ans = 0;
int main(void) {
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> X[i];
  }
  cin >> A;
  for (int i = 0; i < N; i++) {
    cin >> C[i];
  }
  bool mk = true;
  for (int i = 0; i < N; i++) {
    drinks.insert(C[i]);
    while (K < X[i]) {
      if (drinks.empty()) {
        mk = false;
        break;
      } else {
        auto it = drinks.begin();
        ans += (*it);
        drinks.erase(it);
        K += A;
      }
    }
    if (!mk) {
      break;
    }
  }
  if (!mk) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}
