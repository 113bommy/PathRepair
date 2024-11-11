#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, distinct1 = 0, distinct2 = 0;
  cin >> n;
  int count[100] = {0};
  int heap1[100] = {0};
  bool decide[100];
  int array[2 * 100];
  bool flag = true, set = true;
  for (i = 0; i < 2 * n; ++i) {
    cin >> array[i];
    ++count[array[i]];
  }
  for (i = 0; i < 100; ++i) {
    if (count[i] >= 2) {
      distinct1++;
      distinct2++;
      if (count[i] & 1) {
        if (set) {
          decide[i] = true;
          set = false;
        } else {
          decide[i] = false;
          set = true;
        }
      } else
        decide[i] = true;
    } else if (count[i] == 1 && flag) {
      distinct1++;
      flag = false;
    } else if (count[i] == 1 && !flag) {
      distinct2++;
      flag = true;
    }
  }
  cout << distinct1 * distinct2 << "\n";
  flag = false;
  for (i = 0; i < 2 * n; ++i) {
    if (count[array[i]] == 1 && flag) {
      cout << "1 ";
      flag = false;
    } else if (count[array[i]] == 1 && !flag) {
      cout << "2 ";
      flag = true;
    } else if (count[array[i]] >= 2 && decide[array[i]]) {
      cout << "1 ";
      decide[array[i]] = false;
    } else if (count[array[i]] >= 2 && !decide[array[i]]) {
      cout << "2 ";
      decide[array[i]] = true;
    }
  }
  cout << "\n";
  return 0;
}
