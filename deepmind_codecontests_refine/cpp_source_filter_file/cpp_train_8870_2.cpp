#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  long long n, a, b, k;
  cin >> n >> a >> b >> k;
  vector<long long> ans;
  long long tmp = a + b;
  long long res = 0;
  for (int i = 0; i < n; i++) {
    long long val;
    cin >> val;
    long long rem;
    if (val % tmp == 0)
      rem = tmp;
    else
      rem = val % tmp;
    rem -= a;
    if (rem <= 0)
      res++;
    else {
      if (rem % a == 0)
        ans.push_back(rem / a);
      else
        ans.push_back(ceil(rem / a));
    }
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    if (ans[i] <= k) {
      res++;
      k -= ans[i];
    } else
      break;
  }
  cout << res;
}
