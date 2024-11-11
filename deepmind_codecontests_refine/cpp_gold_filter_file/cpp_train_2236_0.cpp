#include <bits/stdc++.h>
using namespace std;
long long n, k;
multiset<long long> st;
int main() {
  scanf("%I64d%I64d", &n, &k);
  while (k--) st.insert(0);
  for (long long i = 0; i < n; i++) {
    long long a, b;
    scanf("%I64d%I64d", &a, &b);
    long long v = *st.begin();
    st.erase(st.begin());
    v = max(v, a);
    cout << v + b << endl;
    st.insert(v + b);
  }
  return 0;
}
