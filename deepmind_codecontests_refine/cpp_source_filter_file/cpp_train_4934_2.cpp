#include <bits/stdc++.h>
using namespace std;
int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int day2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isvalid(vector<int> &b) {
  if (b[2] % 4 == 0)
    return day2[b[1] - 1] >= b[0] && b[1] > 1 && b[1] <= 12;
  else
    return day[b[1] - 1] >= b[0] && b[1] > 1 && b[1] <= 12;
}
bool calc(vector<int> &b, vector<int> &c) {
  return ((c[2] - b[2] > 18) || (c[2] - b[2] == 18 && c[1] > b[1]) ||
          (c[2] - b[2] == 18 && b[1] == c[1] && c[0] >= b[0]));
}
int main() {
  vector<int> c(3);
  vector<int> b(3);
  scanf("%d.%d.%d", &c[0], &c[1], &c[2]);
  scanf("%d.%d.%d", &b[0], &b[1], &b[2]);
  do {
    if (isvalid(b)) {
      if (calc(b, c)) {
        cout << "YES" << endl;
        return 0;
      }
    }
  } while (next_permutation(b.begin(), b.end()));
  cout << "NO" << endl;
}
