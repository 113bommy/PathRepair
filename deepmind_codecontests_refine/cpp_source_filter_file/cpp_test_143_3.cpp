#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int MOD = 998244353;
int t, n, a[N];
long long ans[N];
int freq[N];
stack<int> st;
int main() {
  scanf("%d", &t);
  while (t--) {
    while (!st.empty()) st.pop();
    scanf("%d", &n);
    for (int i = 0; i <= n + 1; i++) {
      ans[i] = -1;
      freq[i] = 0;
    }
    ans[0] = freq[0];
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      freq[a[i]]++;
    }
    ans[0] = freq[0];
    sort(a, a + n);
    long long cur = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] > i) break;
      while (j < n && a[j] <= i) {
        j++;
        st.push(i);
      }
      int z = st.top();
      st.pop();
      cur += (i - z);
      ans[i + 1] = cur + freq[i + 1];
    }
    for (int i = 0; i <= n; i++) {
      printf("%d ", ans[i]);
    }
    puts("");
  }
  return 0;
}
