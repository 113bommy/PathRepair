#include <bits/stdc++.h>
using namespace std;
map<long long int, long long int> cnt;
set<long long int, greater<long long int> > s;
long long int n, k, ar[1000009], m = -1 * 1e18, i;
int main() {
  cin >> n >> k;
  for (i = 0; i < n; i++) cin >> ar[i];
  for (i = 0; i < k; i++) cnt[ar[i]]++;
  for (i = 0; i < k; i++) {
    if (cnt[ar[i]] == 1) {
      m = max(m, ar[i]);
      s.insert(ar[i]);
    }
  }
  if (m == -1 * 1e18)
    cout << "Nothing" << endl;
  else
    cout << m << endl;
  for (i = k; i < n; i++) {
    cnt[ar[i - k]]--;
    if (cnt[ar[i - k]] == 0)
      s.erase(ar[i - k]);
    else if (cnt[ar[i - k]] == 1)
      s.insert(ar[i - k]);
    cnt[ar[i]]++;
    if (cnt[ar[i]] == 1)
      s.insert(ar[i]);
    else if (cnt[ar[i]] == 2)
      s.erase(ar[i]);
    if (!s.empty())
      cout << *s.begin() << endl;
    else
      cout << "Nothing" << endl;
  }
  return 0;
}
