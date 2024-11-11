#include <bits/stdc++.h>
using namespace std;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const double EPS = 1e-5;
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  set<int> st;
  for (int i = 0; i < n; i++) cin >> x[i], st.insert(x[i]);
  for (int i = 0; i < n; i++) cin >> y[i], st.insert(y[i]);
  int r = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (st.find(x[i] ^ y[j]) != st.end()) r++;
  cout << (r % 2 == 0 ? "Karen" : "Koyomi") << endl;
  cin.ignore(), cin.get();
}
