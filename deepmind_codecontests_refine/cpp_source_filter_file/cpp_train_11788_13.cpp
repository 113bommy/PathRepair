#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& out, vector<T>& v) {
  out << "[";
  for (auto k : v) out << k << " ";
  out << "]"
      << "\n";
  return out;
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int i = 0, L = s.size(), j = L - 1;
    while (s[j] == '0' && j > 0) j--;
    while (s[i] == '0' && i < L - 1) i++;
    if (i >= j)
      cout << 0 << "\n";
    else {
      int res = 0;
      for (int k = int(i); k < int(j); k++)
        if (s[i] == '0') res++;
      cout << res << "\n";
    }
  }
}
