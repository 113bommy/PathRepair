#include <bits/stdc++.h>
using namespace std;
long long int a[100005];
long long int n, len, k;
class data {
 public:
  set<pair<long long int, long long int> > mx, mn;
  long long int sum1, ksum;
  data() { ksum = 0, sum1 = 0; }
  void ins(long long int v, long long int index) {
    sum1 += v;
    ksum += v;
    mx.insert(make_pair(v, index));
    if (int((mx).size()) > k) {
      pair<long long int, long long int> p = *(mx.begin());
      mx.erase(p);
      ksum -= p.first;
      p.first = -p.first;
      mn.insert(p);
    }
  }
  void rem(long long int v, long long int index) {
    sum1 -= v;
    if (mx.count(make_pair(v, index))) {
      ksum -= v;
      mx.erase(make_pair(v, index));
      if (int((mn).size()) > 0) {
        pair<long long int, long long int> p = *(mn.begin());
        mn.erase(p);
        p.first = -p.first;
        mx.insert(p);
        ksum += p.first;
      }
    } else if (mn.count(make_pair(v, index))) {
      mn.erase(make_pair(v, index));
    }
  }
};
data ap, an;
void ADD(long long int v, long long int index) {
  if (v < 0)
    an.ins(-v, index);
  else
    ap.ins(v, index);
}
void REMOVE(long long int v, long long int index) {
  if (v < 0)
    an.rem(-v, index);
  else
    ap.rem(v, index);
}
int main() {
  long long int ans = 0;
  cin >> n >> len;
  for (long long int i = 0; i < n; i++) cin >> a[i];
  cin >> k;
  for (long long int i = 0; i < n; i++) {
    ADD(a[i], i);
    if (i >= len) REMOVE(a[i - len], i - len);
    if (i >= len - 1)
      ans = max(ans, max(ap.sum1 - an.sum1 + 2 * an.ksum,
                         an.sum1 + 2 * ap.ksum - ap.sum1));
  }
  cout << ans << endl;
  return 0;
}
