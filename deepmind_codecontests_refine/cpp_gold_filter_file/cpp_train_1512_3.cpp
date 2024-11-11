#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
using namespace std;
map<int, int> st;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    st[a]++;
  }
  if (n == 1) {
    printf("0");
    return 0;
  }
  int res = 0;
  while (true) {
    int a = st.begin()->first;
    int cnta = st.begin()->second;
    int b = (--st.end())->first;
    int cntb = (--st.end())->second;
    if (b - a <= 1) break;
    int cnt = min(cnta, cntb);
    res += cnt;
    st[a] -= cnt;
    st[b] -= cnt;
    if (st[a] == 0) st.erase(a);
    if (st[b] == 0) st.erase(b);
    st[a + 1] += cnt;
    st[b - 1] += cnt;
  }
  printf("%d", res);
  return 0;
}
