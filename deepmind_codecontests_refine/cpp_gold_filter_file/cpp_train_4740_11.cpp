#include <bits/stdc++.h>
using namespace std;
int ans[10001];
bool elemn(int i) {
  int arr[10] = {0};
  while (i > 0) {
    arr[i % 10]++;
    i /= 10;
  }
  for (int i = 0; i < 10; i++)
    if (arr[i] > 1) return 1;
  return 0;
}
pair<int, int> sol(int x, int y) {
  pair<int, int> tmp = {0, 0};
  int x1, x2, x3, x4, y1, y2, y3, y4;
  x1 = x / 1000;
  x %= 1000;
  x2 = x / 100;
  x %= 100;
  x3 = x / 10;
  x %= 10;
  x4 = x;
  y1 = y / 1000;
  y %= 1000;
  y2 = y / 100;
  y %= 100;
  y3 = y / 10;
  y %= 10;
  y4 = y;
  if (x1 == y1) tmp.first++;
  if (x2 == y2) tmp.first++;
  if (x3 == y3) tmp.first++;
  if (x4 == y4) tmp.first++;
  int arr[10] = {0};
  arr[x1]++;
  arr[x2]++;
  arr[x3]++;
  arr[x4]++;
  arr[y1]++;
  arr[y2]++;
  arr[y3]++;
  arr[y4]++;
  for (int i = 0; i < 10; i++) {
    if (arr[i] == 2) tmp.second++;
  }
  tmp.second -= tmp.first;
  return tmp;
}
int main() {
  int n, x, so = 1E8;
  cin >> n;
  pair<int, int> guess;
  while (n--) {
    cin >> x >> guess.first >> guess.second;
    for (int i = 0; i < 10001; i++) {
      if (elemn(i)) ans[i] = 1;
      if (ans[i]) continue;
      if (guess != sol(x, i)) ans[i] = 1;
    }
  }
  for (int i = 102; i < 10001; i++) {
    if (ans[i]) continue;
    if (so == 1E8) {
      so = i;
    } else {
      so = -1E8;
    }
  }
  if (so == 1E8)
    cout << "Incorrect data";
  else if (so == -1E8)
    cout << "Need more data";
  else {
    if (so < 1000) cout << 0;
    cout << so;
  }
  return 0;
}
