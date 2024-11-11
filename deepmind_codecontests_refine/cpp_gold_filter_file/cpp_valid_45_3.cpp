#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const long long mod = 1e9 + 7;
const int N = 1e5 + 5, M = 1e5 + 5;
long long T, n, m, q;
bool ok;
string s, t;
void test() {
  cin >> n;
  long long a[n];
  vector<long long> odd, even;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % 2 == 0)
      even.push_back(i);
    else
      odd.push_back(i);
  }
  if (abs((int)odd.size() - (int)even.size()) > 1) {
    cout << "-1\n";
    return;
  }
  long long ans = LONG_LONG_MAX;
  if (n % 2 == 0 || (n % 2 == 1 && even.size() > odd.size())) {
    long long cnt = 0;
    int j = 0, k = 0;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        cnt += abs(i - even[j]);
        j++;
      } else {
        cnt += abs(i - odd[k]);
        k++;
      }
    }
    ans = min(cnt, ans);
  }
  if (n % 2 == 0 || (n % 2 == 1 && even.size() < odd.size())) {
    long long cnt = 0;
    int j = 0, k = 0;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 1) {
        cnt += abs(i - even[j]);
        j++;
      } else {
        cnt += abs(i - odd[k]);
        k++;
      }
    }
    ans = min(cnt, ans);
  }
  cout << ans / 2 << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    test();
  }
}
