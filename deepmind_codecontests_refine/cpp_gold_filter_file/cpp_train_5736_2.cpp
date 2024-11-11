#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int A[N];
long long sum = 0, ans = 0;
bool state;
map<int, int> cnt;
int main() {
  cnt[0] = 1;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < n; i++) {
    if (A[i] > m)
      sum++;
    else if (A[i] < m)
      sum--;
    state = state | (A[i] == m);
    if (state) {
      ans += (cnt[sum] + cnt[sum - 1]);
      continue;
    }
    cnt[sum]++;
  }
  cout << ans << endl;
}
