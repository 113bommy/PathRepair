#include <bits/stdc++.h>
const int mod = 1000 * 1000 * 1000 + 7;
const int half = (mod + 1) / 2;
using namespace std;
int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
int mult(int a, int b) { return (a * (long long)b) % mod; }
int n, k;
int a[1000005];
int l[1000005];
int r[1000005];
int arifm(int n) { return mult(mult(n, n + 1), half); }
int f(int l, int r) {
  if (l > r) swap(l, r);
  int chlenCnt = l / (k - 1);
  int ans = 0;
  if (chlenCnt != 0) {
    ans = chlenCnt;
    ans = add(ans, mult(k - 1, arifm(chlenCnt)));
  }
  int chlenCnt2 = r / (k - 1) - chlenCnt;
  ans = add(ans, mult(l + 1, chlenCnt2));
  int chlenCnt3 = (l + r) / (k - 1) - chlenCnt - chlenCnt2;
  ans = add(ans, mult(l + r, chlenCnt3));
  ans = add(ans, mult(k - 1, arifm(chlenCnt + chlenCnt2)));
  ans = sub(ans, mult(k - 1, arifm(chlenCnt + chlenCnt2 + chlenCnt3)));
  return ans;
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  vector<pair<int, int> > st;
  for (int i = 0; i < n; i++) {
    while (st.size() && st.back().first < a[i]) {
      r[st.back().second] = i - 1;
      st.pop_back();
    }
    st.push_back({a[i], i});
  }
  while (st.size()) {
    r[st.back().second] = n - 1;
    st.pop_back();
  }
  reverse(a, a + n);
  for (int i = 0; i < n; i++) {
    while (st.size() && st.back().first <= a[i]) {
      l[st.back().second] = n - i;
      st.pop_back();
    }
    st.push_back({a[i], n - i - 1});
  }
  while (st.size()) {
    l[st.back().second] = 0;
    st.pop_back();
  }
  reverse(a, a + n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = add(ans, mult(a[i], f(i - l[i], r[i] - i)));
  }
  cout << ans;
}
