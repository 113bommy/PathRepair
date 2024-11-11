#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  if (k >= 1000000LL)
    puts("NO");
  else {
    set<int> st;
    for (int i = (1); i <= (k); ++i) st.insert(n % i);
    if ((int)st.size() < k)
      puts("NO");
    else
      puts("YES");
  }
  return 0;
}
