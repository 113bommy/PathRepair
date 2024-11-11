#include <bits/stdc++.h>
using namespace std;
string a;
int len;
int num[11];
int f[20];
int now[20];
int getans(int x, int y) {
  for (int i = 1; i <= 19; i++) {
    now[i] = f[i];
  }
  if (len == 1) {
    return INT_MAX;
  }
  int anser = 0;
  int aim;
  for (int i = len; i >= 0; i--) {
    if (i == 0) {
      return INT_MAX;
    }
    if (now[i] == y) {
      for (int j = i; j <= len - 1; j++) {
        swap(now[j], now[j + 1]);
      }
      anser += len - i;
      break;
    }
  }
  for (int i = len - 1; i >= 0; i--) {
    if (i == 0) {
      return INT_MAX;
    }
    if (now[i] == x) {
      for (int j = i; j <= len - 2; j++) {
        swap(now[j], now[j + 1]);
      }
      anser += len - 1 - i;
      break;
    }
  }
  if (f[1] == 0) {
    for (int i = 1; i <= len - 1; i++) {
      if (i == len - 1) {
        return INT_MAX;
      }
      if (now[i] != 0) {
        anser += i - 1;
        break;
      }
    }
  }
  return anser;
}
int main() {
  cin >> a;
  len = a.size();
  for (int i = 0; i < a.size(); i++) {
    f[i + 1] = a[i] - '0';
    num[a[i] - '0']++;
  }
  int anser = INT_MAX;
  anser = min(anser, getans(0, 0));
  anser = min(anser, getans(5, 0));
  anser = min(anser, getans(2, 5));
  anser = min(anser, getans(7, 5));
  if (anser == INT_MAX) {
    cout << -1 << endl;
  } else {
    cout << anser << endl;
  }
}
