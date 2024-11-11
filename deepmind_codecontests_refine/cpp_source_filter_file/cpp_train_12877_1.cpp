#include <bits/stdc++.h>
using namespace std;
set<int> st;
int n, a;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a > 0) st.insert(a);
  }
  cout << st.size();
}
