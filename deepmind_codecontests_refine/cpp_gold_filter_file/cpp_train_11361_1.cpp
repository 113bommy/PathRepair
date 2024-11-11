#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, q, i, j, k, l;
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> n >> k;
    string st;
    for (j = 0; j < k; j++)
      for (l = 0; l < n / k; l++) st.push_back('a' + j);
    for (j = 0; j < n % k; j++) st.push_back('a' + j);
    cout << st << "\n";
  }
}
