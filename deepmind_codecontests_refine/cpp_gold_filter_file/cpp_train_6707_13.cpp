#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int l;
  double n = 0, i = 0, e = 0, t = 0;
  std::cin >> s;
  for (int j = 0; j < s.size(); j++) {
    if (s[j] == 'n') {
      n++;
    }
    if (s[j] == 'e') {
      e++;
    }
    if (s[j] == 'i') {
      i++;
    }
    if (s[j] == 't') {
      t++;
    }
  }
  n = round(n / 2 - 1);
  if (n < 0) {
    n = 0;
  }
  e = e / 3;
  double arr[5] = {n, e, i, t, t};
  for (int j = 0; j < 4; j++) {
    for (int j = 0; j < 4; j++) {
      if (arr[j] > arr[j + 1]) {
        arr[j] = arr[j + 1];
      }
    }
  }
  l = arr[0];
  std::cout << l;
}
