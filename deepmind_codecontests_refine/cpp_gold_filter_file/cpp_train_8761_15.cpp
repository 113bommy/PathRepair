#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline istream& operator>>(istream& is, vector<T>& v) {
  for (auto& e : v) {
    cin >> e;
  }
  return is;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  long long first_white = -1, first_black = -1, last_white = -1,
            last_black = -1;
  for (int i = 0; i < n; ++i) {
    if (first_black == -1 && s[i] == '1') {
      first_black = i;
    }
    if (first_white == -1 && s[i] == '0') {
      first_white = i;
    }
    if (s[i] == '1') {
      last_black = i;
    } else {
      last_white = i;
    }
  }
  if (last_white - first_white < k || last_black - first_black < k) {
    cout << "tokitsukaze";
  } else if (last_white - first_white > k || last_black - first_black > k) {
    cout << "once again";
  } else {
    if (k + 1 == (n >> 1)) {
      cout << "once again";
    } else {
      cout << "quailty";
    }
  }
  return 0;
}
