#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
string s[1001];
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int r = 500000000;
  int val = r;
  cout << "0 0" << endl;
  int i = 0;
  cin >> s[i++];
  if (n == 1) {
    cout << "2 1 0 1";
    return 0;
  }
  int ly = 0;
  bool inc = true;
  while (i < n) {
    cout << r << " " << r << endl;
    cin >> s[i++];
    val /= 2;
    if (s[i - 1] != s[i - 2]) {
      inc = !inc;
    }
    r = r + (inc ? 1 : -1) * val;
    if (i == n) {
      r = r + (inc ? 1 : -1);
      cout << r + 1 << " " << r << " " << r << " " << r + 1 << endl;
      return 0;
    }
    ly = r;
  }
  return 0;
}
