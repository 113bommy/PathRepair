#include <bits/stdc++.h>
using namespace std;
const int fx[] = {+1, -1, +0, +0};
const int fy[] = {+0, +0, +1, -1};
char ans[55][55];
int main() {
  vector<int> arr(5);
  for (int i = 0; i < 4; i++) cin >> arr[i];
  int cnt = 0;
  for (int i = 0; i < 40; i++) {
    for (int j = 0; j < 40; j++) {
      ans[i][j] = '.';
    }
  }
  int a = 1, b = 1, c = 1, d = 1;
  char bosa;
  for (int i = 0; i < 40; i++) {
    for (int j = 0; j < 40; j++) {
      if (i >= 0 && i <= 9) {
        ans[i][j] = 'C';
      } else if (i >= 10 && i <= 19) {
        ans[i][j] = 'D';
      } else if (i >= 20 && i <= 29) {
        ans[i][j] = 'A';
      } else
        ans[i][j] = 'B';
    }
  }
  int f = 0;
  for (int i = 0; i <= 9; i += 2) {
    for (int j = 0; j < 40; j += 2) {
      if (a != arr[0]) {
        ans[i][j] = 'A';
        a++;
        if (a == arr[0]) {
          f = 1;
          break;
        }
      }
    }
    if (f == 1) break;
  }
  f = 0;
  for (int i = 10; i <= 19; i += 2) {
    for (int j = 0; j < 40; j += 2) {
      if (b != arr[1]) {
        ans[i][j] = 'B';
        b++;
        if (b == arr[1]) {
          f = 1;
          break;
        }
      }
    }
    if (f == 1) break;
  }
  f = 0;
  for (int i = 20; i <= 29; i += 2) {
    for (int j = 0; j < 40; j += 2) {
      if (c != arr[2]) {
        ans[i][j] = 'C';
        c++;
        if (c == arr[2]) {
          f = 1;
          break;
        }
      }
    }
    if (f == 1) break;
  }
  f = 0;
  for (int i = 30; i <= 39; i += 2) {
    for (int j = 0; j < 40; j += 2) {
      if (d != arr[3]) {
        ans[i][j] = 'D';
        d++;
        if (d == arr[3]) {
          f = 1;
          break;
        }
      }
    }
    if (f == 1) break;
  }
  cout << "40"
       << " "
       << "40" << endl;
  for (int i = 0; i < 40; i++) {
    for (int j = 0; j < 40; j++) {
      cout << ans[i][j];
    }
    cout << endl;
  }
}
