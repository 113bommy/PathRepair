#include <bits/stdc++.h>
using namespace std;
int A[15];
set<int> st;
void f(int i, int sum, int n) {
  if (i == n) {
    st.insert(sum);
    return;
  }
  for (int a : {1, 5, 10, 50}) {
    f(i + 1, sum + a, n);
  }
}
int main() {
  for (int i = 1; i < 13; ++i) {
    st.clear();
    f(0, 0, i);
    A[i] = st.size();
  }
  int n;
  scanf("%d", &n);
  if (n < 13)
    printf("%d\n", A[n]);
  else
    printf("%lld\n", (n - 12) * 1LL * 49 + A[12]);
}
