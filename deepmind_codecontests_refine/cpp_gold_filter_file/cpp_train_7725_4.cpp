#include <bits/stdc++.h>
using namespace std;
bool b[100005];
long long mx[100005], mn[100005];
vector<long long> v, q;
int main() {
  long long n, ans = 0, c = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long l;
    cin >> l;
    long long mxx = 0, mnn = 1000000;
    for (int j = 0; j < l; j++) {
      long long x;
      cin >> x;
      if (j == 0) {
        mxx = x;
        mnn = x;
        continue;
      }
      if (x > mnn) {
        b[i] = 1;
        c++;
      }
      mxx = max(mxx, x);
      mnn = min(mnn, x);
    }
    if (b[i]) {
      mn[i] = -1;
      mx[i] = 1000001;
    } else {
      mn[i] = mnn;
      mx[i] = mxx;
    }
    v.push_back(mx[i]);
    q.push_back(mn[i]);
  }
  sort(v.begin(), v.end());
  sort(q.begin(), q.end());
  for (int i = 0; i < n; i++) {
    long long y = upper_bound(v.begin(), v.end(), mn[i]) - v.begin();
    long long u = v.size();
    ans += u - y;
  }
  cout << ans << endl;
  return 0;
}
