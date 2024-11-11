#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
const int mod = 1e9 + 7;
int n, sz[N];
double ar[N];
long long sum[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &ar[i]);
    sum[i] = sum[i - 1] + ar[i];
    sz[i] = 1;
  }
  vector<int> st;
  for (int i = 1; i <= n; i++) {
    while (st.size()) {
      int top = st.back();
      if (ar[top] < ar[i]) break;
      st.pop_back();
      ar[i] = (sum[i] - sum[i - sz[top] - sz[i]]);
      sz[i] = sz[i] + sz[top];
      ar[i] = ar[i] / sz[i];
    }
    st.push_back(i);
  }
  int i = 1, j = 0;
  while (j < st.size()) {
    while (i <= st[j]) {
      printf("%.9lf\n", ar[st[j]]);
      i++;
    }
    j++;
  }
  return 0;
}
