#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
bool isComposite(int n) {
  if (n <= 1) return false;
  if (n <= 3) return false;
  if (n % 2 == 0 || n % 3 == 0) return true;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return true;
  return false;
}
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int sum = accumulate(v.begin(), v.end(), 0);
  int temp;
  if (isComposite(sum)) {
    cout << n;
    cout << "\n";
    for (int i = 0; i < n; i++) {
      cout << i + 1 << " ";
    }
    return;
  } else {
    cout << n - 1;
    cout << "\n";
    for (int i = 0; i < n; i++) {
      if (isComposite(sum - v[i])) {
        temp = v[i];
      }
    }
    for (int i = 0; i < n; i++) {
      if (v[i] == temp) {
        continue;
      }
      cout << i + 1 << " ";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tt;
  cin >> tt;
  for (int i = 0; i < tt; i++) {
    solve();
    cout << endl;
  }
}
