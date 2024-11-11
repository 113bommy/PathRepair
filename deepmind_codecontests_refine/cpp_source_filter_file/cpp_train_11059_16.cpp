#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << "; ";
  err(++it, args...);
}
int main() {
  int noTestCases;
  cin >> noTestCases;
  while (noTestCases-- > 0) {
    string s;
    cin >> s;
    s += "R";
    long long length = s.length();
    long long maximumDistance = -1;
    long long currentDistance;
    for (long long i = 0; i < length; i++) {
      currentDistance += 1;
      if (s[i] == 'R') {
        if (currentDistance > maximumDistance) {
          maximumDistance = currentDistance;
        }
        currentDistance = 0;
      }
    }
    cout << maximumDistance << endl;
  }
  return 0;
}
