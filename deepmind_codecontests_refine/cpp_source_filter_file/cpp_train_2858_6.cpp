#include <bits/stdc++.h>
using namespace std;
char mps[12][100] = {"January",   "February", "March",    "April",
                     "May",       "June",     "July",     "August",
                     "September", "October",  "November", "December"};
int main() {
  int n;
  char maps[100005];
  cin >> maps >> n;
  for (int i = 0; i <= 11; i++) {
    if (!strcmp(mps[i], maps)) {
      cout << mps[(i + 1 + n) % 12 - 1] << endl;
      return 0;
    }
  }
}
