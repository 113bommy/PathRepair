#include <bits/stdc++.h>
using namespace std;
int n, x;
vector<int> st, en;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    if (x) st.push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    if (x) en.push_back(x);
  }
  for (int i = 0; i < n - 1; i++)
    if (en[i] == st[0]) {
      int pst = 0, pen = i;
      while (pst < n - 1) {
        if (st[pst] != en[pen]) return printf("NO"), 0;
        pst++;
        pen++;
        if (pen == n - 1) pen = 0;
      }
      break;
    }
  printf("YES");
}
