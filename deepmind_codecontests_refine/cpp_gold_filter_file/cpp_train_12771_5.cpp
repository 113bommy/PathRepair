#include <bits/stdc++.h>
using namespace std;
void initialise(char arr[48][50]) {
  for (int i = 0; i < 48; ++i) {
    char c;
    if (i / 12 == 0)
      c = 'A';
    else if (i / 12 == 1)
      c = 'B';
    else if (i / 12 == 2)
      c = 'C';
    else
      c = 'D';
    for (int j = 0; j < 50; ++j) {
      arr[i][j] = c;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << 48 << "  " << 50 << "\n";
  char arr[48][50];
  initialise(arr);
  int count = 0;
  for (int i = 0; i < 12; i += 2) {
    if (count >= c - 1) break;
    for (int j = 0; j < 48; j += 2) {
      if (count >= c - 1) break;
      arr[i][j] = 'C';
      count++;
    }
  }
  count = 0;
  for (int i = 12; i < 24; i += 2) {
    if (count >= d - 1) break;
    for (int j = 0; j < 48; j += 2) {
      if (count >= d - 1) break;
      arr[i][j] = 'D';
      count++;
    }
  }
  count = 0;
  for (int i = 24; i < 36; i += 2) {
    if (count >= a - 1) break;
    for (int j = 0; j < 48; j += 2) {
      if (count >= a - 1) break;
      arr[i][j] = 'A';
      count++;
    }
  }
  count = 0;
  for (int i = 36; i < 48; i += 2) {
    if (count >= b - 1) break;
    for (int j = 0; j < 48; j += 2) {
      if (count >= b - 1) break;
      arr[i][j] = 'B';
      count++;
    }
  }
  for (int i = 0; i < 48; ++i) {
    for (int j = 0; j < 50; ++j) {
      cout << arr[i][j];
    }
    cout << "\n";
  }
  return 0;
}
