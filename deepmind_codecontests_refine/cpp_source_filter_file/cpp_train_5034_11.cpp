#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 * 1000 + 10;
int N;
int a[MAXN];
int sum;
vector<int> v;
long long ans = 0;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % 3) {
    cout << 0 << endl;
    return 0;
  }
  int now = 0;
  for (int i = 0; i < N; ++i) {
    now += a[i];
    if (now == sum / 3) {
      v.push_back(i);
    }
  }
  int last = ((int)(v).size()) - 1;
  now = 0;
  for (int i = N - 1; i >= 0; --i) {
    now += a[i];
    if (now == sum / 3) {
      while (0 <= last && i <= v[last]) --last;
      ans += (last + 1);
    }
  }
  cout << ans << endl;
  return 0;
}
