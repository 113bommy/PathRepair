#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vpii = vector<pair<int, int>>;
using vs = vector<string>;
void solve() {
  int n;
  cin >> n;
  vector<int> arr(2 * n);
  for (auto &item : arr) {
    cin >> item;
  }
  int answer = 0;
  int count = 0;
  vector<int> store(n + 1);
  for (int i = 0; i < 2 * n; i++) {
    if (store[arr[i]] == 0) {
      store[arr[i]] = 1;
      count++;
    } else {
      store[arr[i]]--;
      count--;
    }
    answer = max(answer, count);
  }
  cout << answer << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
}
