#include <bits/stdc++.h>
using namespace std;
int main() {
  int year = 1000, k = 0, n = 0;
  string year_text = "";
  cin >> year;
  year++;
  for (long long i = year; i < 9001; i++) {
    year_text = to_string(i);
    for (int j = 0; j < 4; j++) {
      for (int ii = 0; ii < 4; ii++) {
        if (year_text[j] == year_text[ii] && j != ii) {
          k = 1;
          break;
        }
      }
      if (k == 1) {
        k = 0;
        n = 0;
        break;
      }
      n++;
      if (n == 4) {
        cout << i;
        return 0;
      }
    }
  }
}
