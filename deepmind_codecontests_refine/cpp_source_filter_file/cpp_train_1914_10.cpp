#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 2;
const long long mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  vector<long long> cnt(200);
  long long n;
  cin >> n;
  set<long long> st;
  vector<long long> age(100);
  for (int i = 1; i < n; i++) st.insert(i + 1);
  vector<long long> f, s;
  set<long long> boro[100], choto[100];
  for (int i = 0; i + 1 < n * (n - 1) / 2; i++) {
    long long x, y;
    cin >> x >> y;
    f.push_back(x);
    s.push_back(y);
    cnt[x]++, cnt[y]++;
    if (cnt[x] == n - 1) st.erase(x);
    if (cnt[y] == n - 1) st.erase(y);
    boro[x].insert(y);
    choto[y].insert(x);
  }
  long long a = *st.begin(), b = *--st.end();
  long long aboro = 0;
  for (long long e : boro[a]) {
    for (long long x : boro[e]) {
      if (x == b) {
        aboro = 1;
      }
    }
  }
  if (aboro)
    cout << a << " " << b;
  else
    cout << b << " " << a;
}
