#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int i, j, n, k;
  scanf("%d%d", &n, &k);
  vector<int> kp;
  for (i = 2; i * i <= k; i++)
    if (k % i == 0) {
      int x = 1;
      while (k % i == 0) {
        k /= i;
        x *= i;
      }
      kp.push_back(x);
    }
  if (k > 1) kp.push_back(k);
  for (i = 0; i <= (int)(n)-1; i++) {
    int c;
    scanf("%d", &c);
    for (j = 0; j <= (int)(kp.size()) - 1; j++) {
      if (c % kp[j] == 0) kp.erase(kp.begin() + j);
    }
  }
  if (kp.size() == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
