#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return a ? gcd(b % a, a) : b; }
int x[100];
stack<int> st;
int n, a, b;
int best = 100000;
int nums[100], sum[100], best2[100];
bool z;
void rec(int k) {
  if (k > n - 1) {
    bool z = true;
    int cnt = 0;
    for (int i = 2; i <= n - 1; i++) sum[i] = 0;
    for (int i = 2; i <= n - 1; i++) {
      cnt += nums[i];
      sum[i - 1] += nums[i] * b;
      sum[i] += nums[i] * a;
      sum[i + 1] += nums[i] * b;
    }
    for (int i = 2; i <= n - 1; i++) {
      if (sum[i] <= x[i]) z = false;
    }
    if (z && best > cnt) {
      best = cnt;
      for (int i = 2; i <= n - 1; i++) best2[i] = nums[i];
    }
  } else {
    int to;
    to = x[k] / a + 2;
    to = max(to, 0);
    for (int i = 0; i <= to; i++) {
      nums[k] = i;
      rec(k + 1);
    }
  }
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) cin >> x[i];
  while (x[1] >= 0) {
    st.push(2);
    x[1] -= b;
    x[2] -= a;
    x[3] -= b;
  }
  while (x[n] >= 0) {
    st.push(n - 1);
    x[n - 2] -= b;
    x[n - 1] -= a;
    x[n] -= b;
  }
  rec(2);
  for (int i = 2; i <= n - 1; i++) {
    for (int j = 1; j <= best2[i]; j++) st.push(i);
  }
  cout << st.size() << "\n";
  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
  return 0;
}
