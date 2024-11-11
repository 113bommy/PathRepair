#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 10e4;
const long long mn = 0;
const long long mx = 10e17;
long long n, m;
string s;
set<int> st;
int main() {
  ios_base::sync_with_stdio(0);
  ;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> m;
    if (m != 0) st.insert(m);
  }
  cout << st.size();
}
