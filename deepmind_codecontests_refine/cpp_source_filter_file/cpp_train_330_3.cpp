#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
const long long num = 1000000000;
int main() {
  long long q = 1;
  cin >> q;
  while (q--) {
    long long n;
    cin >> n;
    vector<long long> vec(n);
    for (int i = 0; i < n; i++) {
      cin >> vec[i];
    }
    long long g = 0, s = 0, b = 0;
    while (g < n and vec[g] == vec[0]) g++;
    set<long long> st;
    for (int i = g; i < n; i++) {
      if (st.count(vec[i]))
        s++;
      else if (s <= g) {
        st.insert(vec[i]);
        s++;
      } else
        break;
    }
    for (int i = g + s; i < n; i++) {
      if (vec[i] <= vec[n / 2])
        break;
      else
        b++;
    }
    if (!g or !s or !b or g + s + b > n / 2 or s <= g or b <= g) {
      cout << 0 << endl;
    } else {
      cout << g << " " << s << " " << b << endl;
    }
  }
  return 0;
}
