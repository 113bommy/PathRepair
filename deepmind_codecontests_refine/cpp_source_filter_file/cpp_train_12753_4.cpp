#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 6;
int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[] = {0, -1, 1, 0, 1, -1, 1, -1};
int main() {
  double d, s1, s2;
  cin >> d >> s1 >> s2;
  cout << (d * max(s1, s2) / (s1 + s2));
  return 0;
}
