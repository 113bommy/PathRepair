#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  stack<int> st;
  int mx = 0;
  for (int i = 0; i < 11; i++) {
    scanf("%d", &a);
    mx = max(mx, a);
    st.push(a);
  }
  for (int i = 0; i < 11; i++) {
    int k = st.top();
    st.pop();
    double re = pow(k, 3) * 5 + sqrt(abs(k));
    if (re > 400.0) {
      printf("f(%d) = MAGNA NIMIS!\n", k);
    } else {
      printf("f(%d) = %.2lf\n", k, re);
    }
  }
  return 0;
}
