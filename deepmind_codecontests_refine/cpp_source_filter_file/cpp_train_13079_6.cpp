#include <bits/stdc++.h>
using namespace std;
const long long G = 200000;
const long long H = 199939;
signed main() {
  ios_base::sync_with_stdio(false);
  long long n, k;
  cin >> n >> k;
  vector<long long> bit(G);
  fill(bit.begin(), bit.end(), 0);
  for (long long i = 0; i < 61; i++) {
    long long ba = n & (1LL << i);
    if (ba != 0) {
      bit[H + i] = 1;
      k--;
    }
  }
  if (k < 0) {
    cout << "No" << endl;
    return 0;
  }
  for (long long i = G - 1; i > 0; i--) {
    if (bit[i] > k) break;
    bit[i - 1] += 2 * bit[i];
    k -= bit[i];
    bit[i] = 0;
  }
  priority_queue<long long> P;
  for (long long i = 0; i < G; i++) {
    for (long long j = 0; j < bit[i]; j++) P.push(i);
  }
  for (long long i = 0; i < k; i++) {
    long long A = P.top();
    bit[A]--;
    bit[A - 1] += 2;
    P.pop();
    P.push(A - 1);
    P.push(A - 1);
  }
  cout << "Yes" << endl;
  for (long long i = G - 1; i >= 0; i--) {
    while (bit[i] > 0) {
      bit[i]--;
      cout << i - H << " ";
    }
  }
  return 0;
}
