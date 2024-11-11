#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, a[200010], p[200010], c[200010];
long long inv[200010];
set<int> st;
set<int>::iterator it;
int Lowbit(int x) { return x & (-x); }
void Update(int x, int d) {
  while (x <= n) {
    c[x] += d;
    x += Lowbit(x);
  }
}
int Getsum(int x) {
  int res = 0;
  while (x) {
    res += c[x];
    x -= Lowbit(x);
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[a[i]] = i;
  }
  cout << "0 ";
  int center = p[1], lnum = 0, rnum = 0;
  long long sum = 0;
  st.insert(p[1]);
  Update(p[1], 1);
  for (int i = 2; i <= n; ++i) {
    inv[i] = Getsum(n) - Getsum(p[i]);
    Update(p[i], 1);
    st.insert(p[i]);
    long long nxt_sum =
        sum + inv[i] + abs(p[i] - center) - abs(Getsum(center) - Getsum(p[i]));
    if (center < p[i])
      nxt_sum -= inv[i];
    else
      nxt_sum -= Getsum(p[i] - 1);
    if (p[i] > center)
      rnum++;
    else
      lnum++;
    if (lnum == rnum + 1) {
      it = st.find(center);
      it--;
      center = (*it);
      lnum--;
      rnum++;
    }
    if (rnum == lnum + 2) {
      it = st.find(center);
      it++;
      nxt_sum -= ((*it) - center - 1);
      center = (*it);
      lnum++;
      rnum--;
    }
    sum = nxt_sum;
    cout << sum << " ";
  }
  cout << endl;
  return 0;
}
