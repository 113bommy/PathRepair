#include <bits/stdc++.h>
using namespace std;
struct IntCmp {
  bool operator()(const std::pair<std::string, int> &lhs,
                  const std::pair<std::string, int> &rhs) {
    return lhs.second > rhs.second;
  }
};
bool vow(char ch) {
  if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
      ch == 'y')
    return 1;
  else
    return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long s, v1, v2, t1, t2;
  cin >> s >> v1 >> v2 >> t1 >> t2;
  long long Fir = 2 * t1 + v1 * s;
  long long Sec = 2 * t2 + v2 * s;
  if (Fir < Sec)
    cout << "First";
  else if (Sec < Fir)
    cout << "Second";
  else
    cout << "Friendship";
  return 0;
}
