#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int a[N];
pair<int, int> p1[N];
pair<int, int> p2[N];
int main() {
  string s;
  cin >> s;
  if (s[0] == 2 && s.size() == 1) {
    cout << 0;
    return 0;
  }
  long long ans = 0;
  int k = 1;
  int u = s[s.size() - 1] - '0';
  if (u % 2 == 0) {
    k += 1;
  } else {
    k += 4;
  }
  u = (s[s.size() - 2] - '0') * 10 + (s[s.size() - 1] - '0');
  if (u % 4 == 0) {
    k += 2;
  }
  if (u % 4 == 1) {
    k += 5;
  }
  if (u % 4 == 2) {
    k += 8;
  }
  if (u % 4 == 3) {
    k += 5;
  }
  cout << k % 5;
}
