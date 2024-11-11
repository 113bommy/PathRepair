#include <bits/stdc++.h>
using namespace std;
template <typename T>
string to_string(T str) {
  stringstream stream;
  stream << str;
  return stream.str();
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    long long A, B;
    cin >> A >> B;
    long long x = 9, c = 0;
    while (x <= B) {
      x = x * 10 + 9;
      c++;
    }
    cout << A * c << endl;
  }
  return 0;
}
