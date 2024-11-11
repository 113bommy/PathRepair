#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long double pi = acos(-1);
const int MOD = 1e9 + 7;
int r[5100];
int main() {
  int n, s1, s2, s3;
  cin >> n;
  cout << "? 1 2" << endl;
  cin >> s1;
  cout << "? 2 3" << endl;
  cin >> s2;
  cout << "? 1 3" << endl;
  cin >> s3;
  r[2] = (s1 - s3 + s2) / 2;
  r[3] = s2 - r[2];
  r[1] = s1 - r[2];
  for (int i = 4; i <= n; i++) {
    cout << "? " << i - 1 << " " << i << endl;
    cin >> s1;
    r[i] = s1 - r[i - 1];
  }
  cout << "! ";
  for (int i = 1; i <= n; i++) {
    cout << r[1] << " ";
  }
  cout << endl;
  return 0;
}
