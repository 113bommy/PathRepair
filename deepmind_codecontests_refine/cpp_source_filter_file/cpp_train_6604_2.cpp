#include <bits/stdc++.h>
using namespace std;
const double PI = 3.141592654;
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL), cout.tie(NULL);
}
int main() {
  fast();
  long long mx = LLONG_MIN;
  int arr[5][5];
  vector<int> v = {2, 3, 1, 5, 4};
  for (int(i) = 0; (i) < (long long)(5); (i)++) {
    for (int(j) = 0; (j) < (long long)(5); (j)++) cin >> arr[i][j];
  }
  do {
    long long sum = 0;
    deque<int> dq((v).begin(), (v).end());
    while (dq.size() > 1) {
      for (int i = 0; i < dq.size() - 1; i += 2) {
        sum += arr[dq[i] - 1][dq[i + 1] - 1];
        sum += arr[dq[i + 1] - 1][dq[i] - 1];
      }
      dq.pop_front();
    }
    mx = max(mx, sum);
  } while (next_permutation((v).begin(), (v).end()));
  cout << mx;
  return 0;
}
