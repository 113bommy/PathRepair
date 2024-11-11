#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int x, y, z, t1, t2, t3;
int main() {
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  int dif = abs(x - y);
  int stair = dif * t1;
  int lift = dif * t2;
  int temp = abs(x - z);
  lift += temp * t2;
  lift += t3 + t3 + t3;
  if (lift <= stair)
    puts("YES");
  else
    puts("NO");
  return 0;
}
