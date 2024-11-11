#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
long long read_ll() {
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  long long ret = 0;
  int neg = 0;
  if (c == '-') neg = 1, c = getchar();
  while (c >= '0' && c <= '9') {
    ret = 10 * ret + c - 48;
    c = getchar();
  }
  return neg ? -ret : ret;
}
int main() {
  long long n, i;
  n = read_ll();
  long long a[n + 2], mini = INT_MAX, maxi = INT_MIN;
  a[0] = INT_MIN;
  a[n + 1] = INT_MIN;
  for (i = 1; i <= n; i++) {
    a[i] = read_ll();
    mini = min(a[i], mini);
    maxi = max(a[i], maxi);
  }
  long long leftmin[n + 1], rightmin[n + 1], leftmax[n + 1], rightmax[n + 1];
  memset(leftmax, 0, sizeof(leftmax));
  memset(rightmin, 0, sizeof(rightmin));
  memset(rightmax, 0, sizeof(rightmax));
  memset(leftmin, 0, sizeof(leftmin));
  stack<long long> st;
  st.push(0);
  for (i = 1; i <= n; i++) {
    while (a[st.top()] >= a[i]) st.pop();
    leftmin[i] = st.top();
    st.push(i);
  }
  while (!st.empty()) st.pop();
  st.push(n + 1);
  for (i = n; i >= 1; i--) {
    while (a[st.top()] >= a[i]) st.pop();
    rightmin[i] = st.top();
    st.push(i);
  }
  while (!st.empty()) st.pop();
  a[0] = INT_MAX, a[n + 1] = INT_MAX;
  st.push(0);
  for (i = 1; i <= n; i++) {
    while (a[st.top()] <= a[i]) st.pop();
    leftmax[i] = st.top();
    st.push(i);
  }
  while (!st.empty()) st.pop();
  st.push(n + 1);
  for (i = n; i >= 1; i--) {
    while (a[st.top()] <= a[i]) st.pop();
    rightmax[i] = st.top();
    st.push(i);
  }
  long long minsum = mini, maxsum = maxi, res = 0;
  for (i = 1; i <= n; i++) {
    long long cnt = (rightmax[i] - i) * (i - leftmax[i]) -
                    (rightmin[i] - i) * (i - leftmin[i]);
    res += cnt * a[i];
  }
  cout << res;
  return 0;
}
