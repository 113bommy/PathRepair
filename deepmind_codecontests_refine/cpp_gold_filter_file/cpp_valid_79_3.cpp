#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &output, const vector<T> &vec) {
  if (vec.empty()) return output;
  for (int i = 0; i < vec.size() - 1; i++) output << vec[i] << " ";
  output << vec.back();
  return output;
}
template <typename T>
istream &operator>>(istream &input, vector<T> &vec) {
  for (auto &i : vec) cin >> i;
  return input;
}
long long nxt() {
  long long i;
  cin >> i;
  return i;
}
void fun() {
  long long k;
  cin >> k;
  string s;
  cin >> s;
  vector<int> cnt(10, 0);
  for (long long i = 0; i < k; i++) {
    cnt[s[i] - '0']++;
    if (s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' ||
        s[i] == '9') {
      cout << 1 << "\n" << s[i] << "\n";
      return;
    }
  }
  for (long long i = 1; i < 10; i++) {
    if (cnt[i] >= 2) {
      cout << 2 << "\n" << (char)('0' + i) << (char)('0' + i) << "\n";
      return;
    }
  }
  if (cnt[2] == 1 && s[0] != '2')
    cout << 2 << "\n" << s[0] << 2 << "\n";
  else if (cnt[5] == 1 && s[0] != '5')
    cout << 2 << "\n" << s[0] << 5 << "\n";
  else if (s == "237")
    cout << 2 << "\n" << 27 << "\n";
  else if (s == "273")
    cout << 2 << "\n" << 27 << "\n";
  else if (s == "537")
    cout << 2 << "\n" << 57 << "\n";
  else if (s == "573")
    cout << 2 << "\n" << 57 << "\n";
  else
    cout << s.length() << "\n" << s << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) fun();
  return 0;
}
