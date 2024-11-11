#include <bits/stdc++.h>
using namespace std;
int main() {
  map<string, int> backnames;
  string names[7] = {"Anka",        "Chapay", "Cleo", "Dracul",
                     "Hexadecimal", "Snowy",  "Troll"};
  for (int i = 0; i < 7; i++) backnames[names[i]] = i;
  bool like[7][7];
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      like[i][j] = 0;
    }
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string a, b, c;
    cin >> a >> b >> c;
    like[backnames[a]][backnames[c]] = 1;
  }
  int a, b, c;
  cin >> a >> b >> c;
  int exp_diff = 2E9;
  int like_m = 0;
  int x = 0, y = 0, z = 0;
  for (int x = 1; x <= 5; x++) {
    for (int y = 1; y <= 6 - x; y++) {
      z = 7 - x - y;
      int arr[7];
      for (int i = 1; i <= 7; i++) arr[i] = i;
      do {
        int p = min(a / x, b / y), q = max(a / x, b / y);
        p = min(p, c / z);
        q = max(q, c / z);
        int diff = q - p;
        if (diff > exp_diff) continue;
        int clike = 0;
        for (int i = 0; i < x; i++) {
          for (int j = 0; j < x; j++) {
            if (i != j) {
              clike += like[arr[i]][arr[j]];
            }
          }
        }
        for (int i = x; i < x + y; i++) {
          for (int j = x; j < x + y; j++) {
            if (i != j) {
              clike += like[arr[i]][arr[j]];
            }
          }
        }
        for (int i = x + y; i < x + y + z; i++) {
          for (int j = x + y; j < x + y + z; j++) {
            if (i != j) {
              clike += like[arr[i]][arr[j]];
            }
          }
        }
        if (diff < exp_diff || (diff == exp_diff && clike > like_m)) {
          exp_diff = diff;
          like_m = clike;
        }
      } while (next_permutation(arr, arr + 7));
    }
  }
  cout << exp_diff << " " << like_m << endl;
}
