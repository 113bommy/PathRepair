#include <bits/stdc++.h>
using namespace std;
int qq = 0, n, m, x[25][25], oneI = 0, oneJ, centerI = 3, centerJ = 3, cs = 0,
    sec, a, b, c, sum = 0, p, q, x1, x2, F[1000000], equalz = 0, endzz = 0,
    minF = 100000;
string abc = "", abc1 = "", abc2 = "", str, str1;
char ch;
int main() {
  cin >> a;
  for (int i = 1; i <= a; i++) {
    cin >> F[i];
  }
  sort(F + 1, F + a + 1);
  for (int i = 1; i <= a; i++) {
    sum = abs(F[i] - F[i + 1]);
    if (sum < minF) {
      minF = sum;
    }
  }
  for (int i = 1; i < a; i++) {
    oneI = abs(F[i] - F[i + 1]);
    if (minF == oneI) {
      cs++;
    }
  }
  cout << minF << " ";
  cout << cs;
  return 0;
}
