#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
char arr[1000][1000];
void printL(int I, int J, int h) {
  arr[I][J] = '+';
  arr[I][J + 1] = '-';
  arr[I + h - 1][J] = '+';
  arr[I + h - 1][J + 1] = '-';
  for (int i = I + 1; i < I + h - 1; i++) arr[i][J] = '|';
}
void printR(int I, int J, int h) {
  arr[I][J] = '+';
  arr[I][J - 1] = '-';
  arr[I + h - 1][J] = '+';
  arr[I + h - 1][J - 1] = '-';
  for (int i = I + 1; i < I + h - 1; i++) arr[i][J] = '|';
}
void show() {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) cout << arr[i][j];
    cout << endl;
  }
}
int main() {
  for (int i = 0; i < 1000; i++)
    for (int j = 0; j < 1000; j++) arr[i][j] = ' ';
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> pos;
  int h = -1;
  int Max = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '[') {
      h++;
      pos.push_back(h);
      if (Max < h) Max = h;
    } else {
      pos.push_back(h);
      h--;
    }
  }
  for (int i = 0; i < n; i++) pos[i] = Max - pos[i];
  for (int i = 0; i < n; i++) pos[i] = 3 + pos[i] * 2;
  Max = 3 + Max * 2;
  int I = -1, J = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '[') {
      I++;
      J++;
      printL(I, J, pos[i]);
    } else {
      if (s[i - 1] == '[') {
        J += 4;
        printR(I, J, pos[i]);
        I--;
      }
      if (s[i - 1] == ']') {
        J++;
        printR(I, J, pos[i]);
        I--;
      }
    }
  }
  for (int i = 0; i < Max; i++) {
    for (int j = 0; j <= J; j++) cout << arr[i][j];
    if (i != Max - 1) cout << endl;
  }
}
