#include <bits/stdc++.h>
using namespace std;
int male[380];
int female[380];
int main() {
  int n;
  char s;
  int a, b;
  cin >> n;
  int maxval = INT_MIN;
  while (n--) {
    cin >> s >> a >> b;
    if (s == 'F') {
      female[a] += 1;
      female[b + 1] -= 1;
    } else {
      male[a] += 1;
      male[b + 1] -= 1;
    }
  }
  for (int i = 1; i <= 365; i++) {
    male[i] += male[i - 1];
    female[i] += female[i - 1];
    maxval = max(maxval, 2 * min(male[i], female[i]));
  }
  cout << maxval << endl;
  return 0;
}
