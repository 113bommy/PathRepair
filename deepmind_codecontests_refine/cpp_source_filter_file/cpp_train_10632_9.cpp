#include <bits/stdc++.h>
template <typename T>
std::ostream &operator<<(std::ostream &os, std::vector<T> vec) {
  os << "{ ";
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(os, " "));
  os << "}";
  return os;
}
using namespace std;
int main(int argc, char const *argv[]) {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  string s;
  cin >> s;
  int answer = 0;
  for (int i = 0, j = 0; i < s.length(); i = j) {
    while (s[i] == s[j]) ++j;
    sort(a.begin() + i, a.begin() + j, greater<int>());
    for (int t = 0, index = i; t < k && index < j; ++t, ++index) {
      answer += a[index];
    }
  }
  cout << answer << '\n';
  return 0;
}
