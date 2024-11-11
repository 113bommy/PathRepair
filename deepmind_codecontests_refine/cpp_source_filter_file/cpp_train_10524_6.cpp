#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
  int n, sum = 0, cnt = 0, a, b, c, d, th;
  cin >> n;
  cin >> a >> b >> c >> d;
  th = a + b + c + d;
  while (n--) {
    cin >> a >> b >> c >> d;
    sum = a + b + c + d;
    if (sum > th) cnt++;
  }
  cout << cnt + 1;
}
