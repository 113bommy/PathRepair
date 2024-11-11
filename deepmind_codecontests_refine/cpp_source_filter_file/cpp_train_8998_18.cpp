#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  getline(cin, s);
  int lt;
  int l = stoi(s.substr(s.size() - 1, 1));
  if (s.size() >= 2) {
    lt = stoi(s.substr(s.size() - 2, 2));
  } else {
    lt = l;
  }
  int tworem;
  int threerem;
  int fourrem;
  int t = l / 2;
  if (lt % 2 == 0) {
    tworem = (t % 2 == 0) ? 4 : 1;
  } else {
    tworem = (t % 2 == 0) ? 2 : 3;
  }
  if (lt % 2 == 0) {
    threerem = (t % 2 == 0) ? 4 : 1;
  } else {
    threerem = (t % 2 == 0) ? 3 : 2;
  }
  fourrem = (l % 2 == 0) ? 1 : 4;
  cout << (1 + tworem + threerem + fourrem) % 5 << endl;
}
int main() { solve(); }
