#include <bits/stdc++.h>
using namespace std;
bool debug = false;
vector<int> G[(3 * 100000 + 42)];
long long n, k, A, B;
vector<long long> arr((3 * 100000 + 42));
long long ans(long long l, long long r) {
  auto it1 = lower_bound(arr.begin(), arr.end(), l);
  auto it2 = lower_bound(arr.begin(), arr.end(), r);
  if (*it1 > r) return A;
  while (it2 == arr.end() or *it2 > r) it2--;
  long long d = it2 - it1 + 1;
  long long cost = d * B * (r - l + 1);
  if (d == 0) return A;
  if (r == l) return cost;
  long long ansl = ans(l, (r + l) / 2);
  long long ansr = ans((r + l) / 2 + 1, r);
  return min(cost, ansl + ansr);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k >> A >> B;
  for (int i = 0; i < k; i++) cin >> arr[i];
  sort(arr.begin(), arr.end());
  cout << ans(1, (1 << n)) << endl;
  return 0;
}
