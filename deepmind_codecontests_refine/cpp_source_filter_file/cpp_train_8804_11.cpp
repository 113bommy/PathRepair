#include <bits/stdc++.h>
using namespace std;
struct Ring {
  int b, a, h;
};
Ring ri[100005];
stack<Ring> st;
bool cmp(Ring x, Ring y) {
  if (x.b == y.b)
    return x.a > y.a;
  else
    return x.b > y.b;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &ri[i].a, &ri[i].b, &ri[i].h);
  }
  sort(ri, ri + n, cmp);
  st.push(ri[0]);
  long long ans = 0, sum = ri[0].h;
  for (int i = 1; i < n; i++) {
    while (!st.empty() && ri[i].b <= st.top().a) {
      sum -= st.top().h;
      st.pop();
    }
    sum += ri[i].h;
    ans = max(ans, sum);
    st.push(ri[i]);
  }
  printf("%lld\n", ans);
  return 0;
}
