#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long n, x, y;
    cin >> n >> x >> y;
    set<long long> st;
    st.insert(x);
    st.insert(y);
    for (int i = 1; i < 50; i++) {
      if ((y - x) % i == 0 && (n - 2) > (y - x) / i - 2) {
        if (x % i == 0)
          for (int j = max(x % i + i, x - (n - (y - x) / i + 1) * i), k = 0;
               k < n; j += i, k++)
            st.insert(j);
        else
          for (int j = max(x % i, x - (n - (y - x) / i + 1) * i), k = 0; k < n;
               j += i, k++)
            st.insert(j);
        break;
      }
    }
    for (auto to : st) cout << to << " ";
    cout << endl;
    st.clear();
  }
}
