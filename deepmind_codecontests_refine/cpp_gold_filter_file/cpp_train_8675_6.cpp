#include <bits/stdc++.h>
using namespace std;
long long n, rH = 1, rW = 1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if (s == "UL" or s == "DR") {
      ++rH;
    } else if (s == "UR" or s == "DL") {
      ++rW;
    } else {
      ++rW, ++rH;
    }
  }
  cout << rW * rH;
}
