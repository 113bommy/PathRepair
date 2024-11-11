#include <bits/stdc++.h>
using namespace std;
void ff() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
void in_out_txt() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
set<long long> st;
void find(long long n, long long p, bool &found) {
  for (int i = 0; i < 25; i++) {
    n = (n * 96 + 42) % 475;
    if (n + 26 == p) found = 1;
    st.insert(n + 26);
  }
}
int main() {
  ff();
  long long p, s, y, x;
  long long count = 0;
  cin >> p >> s >> y;
  bool found = 0;
  long long n;
  n = (s / 50) % 475;
  find(n, p, found);
  x = s;
  while (!found && x >= y) {
    x -= 50;
    st.clear();
    n = (x / 50) % 475;
    find(n, p, found);
    st.clear();
    if (found) break;
    n = ((x + 100) / 50) % 475;
    find(n, p, found);
    if (found) count++;
  }
  while (!found) {
    count++;
    s += 100;
    st.clear();
    n = (s / 50) % 475;
    find(n, p, found);
    if (found) break;
    st.clear();
    n = ((s - 50) / 50) % 475;
    find(n, p, found);
  }
  cout << count << endl;
  return 0;
}
