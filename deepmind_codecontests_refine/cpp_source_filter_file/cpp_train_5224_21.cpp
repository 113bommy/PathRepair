#include <bits/stdc++.h>
using namespace std;
int arr[10];
void left() {
  for (int i = 0; i <= 9; i++) {
    if (arr[i] == 0) {
      arr[i] = 1;
      return;
    }
  }
}
void right() {
  for (int j = 9; j >= 0; j--) {
    if (arr[j] == 0) {
      arr[j] = 1;
      return;
    }
  }
}
void leave(int x) { arr[x] = 0; }
int main() {
  int n;
  cin >> n;
  char c[n];
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 0; i <= 9; i++) arr[i] = 0;
  for (int i = 0; i < n; i++) {
    if (isalpha(c[i])) {
      if (c[i] == 'L') left();
      if (c[i] == 'R') right();
    } else
      leave(c[i] - 48);
  }
  for (int i = 0; i <= 9; i++) cout << arr[i] << " ";
  return 0;
}
