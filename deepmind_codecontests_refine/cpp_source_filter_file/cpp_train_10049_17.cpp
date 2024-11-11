#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 3;
long long n, k, cnt, ans, sum, a;
deque<long long> v;
void DNM() {
  cin >> n >> k;
  ans = n / 2;
  cnt = min(ans, k);
  ans = cnt;
  a = n - 1;
  sum = 0;
  while (ans--) {
    sum += a;
    a--;
  }
  sum += k * (n - 2 * k);
  a = k - 1;
  while (cnt--) sum += a, a--;
  cout << max(sum, 0ll) << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int Qu_l_uQ = 1;
  while (Qu_l_uQ--) DNM();
}
