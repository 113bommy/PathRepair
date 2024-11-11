#include <bits/stdc++.h>
using namespace std;
int n;
bool c, d;
int num[4] = {0, 0, 0, 0};
string a, b;
int main() {
  cin >> n;
  cin >> a >> b;
  for (int i = 0; i < n; i++) {
    d = (a[i] == '1');
    c = (b[i] == '1');
    num[2 * c + d]++;
  }
  cout << (num[3] * num[0] + num[2] * num[1] + num[0] * num[1]);
  return 0;
}
