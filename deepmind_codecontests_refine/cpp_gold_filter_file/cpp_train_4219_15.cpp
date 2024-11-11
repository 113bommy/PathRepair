#include <bits/stdc++.h>
using namespace std;
int num, siz, n;
int i, j;
int driver[1010];
int main() {
  n = 0;
  cin >> num >> siz;
  for (i = 1; i <= num; i++) {
    cin >> driver[i];
  }
  sort(driver, driver + num + 1);
  for (j = num; j >= 1; j--) {
    siz -= driver[j];
    n++;
    if (siz <= 0) break;
  }
  cout << n << endl;
  return 0;
}
