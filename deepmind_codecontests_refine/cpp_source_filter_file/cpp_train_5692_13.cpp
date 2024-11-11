#include <bits/stdc++.h>
using namespace std;
string s;
int mas[6];
int main() {
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'R') {
      mas[0]++;
    }
    if (s[i] == 'O') {
      mas[1]++;
    }
    if (s[i] == 'Y') {
      mas[2]++;
    }
    if (s[i] == 'G') {
      mas[3]++;
    }
    if (s[i] == 'B') {
      mas[4]++;
    }
    if (s[i] == 'V') {
      mas[5]++;
    }
  }
  sort(mas, mas + 6);
  if (mas[5] == 6) {
    cout << 1;
    return 0;
  }
  if (mas[5] == 5) {
    cout << 1;
    return 0;
  }
  if (mas[5] == 4) {
    cout << 2;
    return 0;
  }
  if (mas[5] == 3 && mas[4] == 3) {
    cout << 2;
    return 0;
  }
  if (mas[5] == 3 && mas[4] == 1) {
    cout << 5;
    return 0;
  }
  if (mas[5] == 3 && mas[4] == 2) {
    cout << 3;
    return 0;
  }
  if (mas[5] == 2 && mas[4] == 2 && mas[3] == 1) {
    cout << 8;
    return 0;
  }
  if (mas[5] == 2 && mas[4] == 1) {
    cout << 15;
    return 0;
  }
  if (mas[5] == 2 && mas[4] == 2 && mas[3] == 2) {
    cout << 15;
    return 0;
  }
  if (mas[5] == 1) {
    cout << 30;
    return 0;
  }
  cin >> s;
  return 0;
}
