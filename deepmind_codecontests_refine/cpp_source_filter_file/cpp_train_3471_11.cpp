#include <bits/stdc++.h>
using namespace std;
const int N = int(1e5 + 5);
int a[N];
pair<int, int> b[N];
bool used[N];
int main() {
  ios_base::sync_with_stdio(0);
  int k, n;
  cin >> n >> k;
  long long B;
  cin >> B;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    b[i - 1] = make_pair(a[i], i);
  }
  sort(b, b + n - 1);
  reverse(b, b + n - 1);
  long long sum = 0;
  for (int i = 0; i < k; i++) {
    sum += b[i].first;
    used[b[i].second] = true;
  }
  for (int i = 0; i < n; i++) {
    if (!used[i]) sum += a[i] - b[k - 1].first;
    if (sum > B) {
      cout << i + 1 << endl;
      return 0;
    }
    if (!used[i]) sum -= a[i] - b[k - 1].first;
  }
  cout << n << endl;
  return 0;
}
