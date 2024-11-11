#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 10;
const int inf = 1e3 + 10;
bool prime[N];
void criba() {
  for (int i = 1; i < N; i++) prime[i] = true;
  prime[1] = false;
  for (int i = 2; i < N; i++) {
    for (int j = i + i; j < N; j += i) {
      prime[j] = false;
    }
  }
}
int main() {
  criba();
  int n;
  cin >> n;
  vector<int> ans;
  for (int i = 2; i <= n; i++) {
    if (prime[i]) {
      int a = i;
      while (a <= n) {
        ans.push_back(a);
        a *= i;
      }
    }
  }
  cout << ans.size() << '\n';
  for (auto x : ans) cout << x << " ";
  cout << '\n';
  return 0;
}
