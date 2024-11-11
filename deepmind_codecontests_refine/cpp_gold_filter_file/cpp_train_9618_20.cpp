#include <bits/stdc++.h>
using namespace std;
string str;
int sg[5042][5042], sg2[5042];
bool used[5042][5042], u2[5042];
int getSG2(int len) {
  if (u2[len]) {
    return sg2[len];
  }
  if (len == 3) {
    return 1;
  }
  if (len < 3) {
    return 0;
  }
  bool ff[14];
  for (int i = 0; i < 14; i++) {
    ff[i] = 0;
  }
  for (int i = 1; i < len - 1; i++) {
    ff[getSG2(i) ^ getSG2(len - 1 - i)] = 1;
  }
  u2[len] = 1;
  for (int i = 0; i < 14; i++) {
    if (!ff[i]) {
      sg2[len] = i;
      return i;
    }
  }
}
int getSG(int s, int f) {
  if (used[s][f]) {
    return sg[s][f];
  }
  if (f - s < 3) {
    return 0;
  }
  bool ff[4];
  for (int i = 0; i < 4; i++) {
    ff[i] = 0;
  }
  used[s][f] = 1;
  if (str[s] != str[s + 2]) {
    sg[s][f] = getSG(s + 1, f);
    return sg[s][f];
  }
  if (str[f - 1] != str[f - 3]) {
    sg[s][f] = getSG(s, f - 1);
    return sg[s][f];
  }
  int cans = -1;
  for (int i = s + 1; i < f - 1; i++) {
    if (str[i - 1] != str[i + 1]) {
      cans = getSG2(i - s + 1) ^ getSG(i, f);
      break;
    }
  }
  if (cans == -1) {
    cans = getSG2(f - s);
  }
  sg[s][f] = cans;
  return cans;
}
int main() {
  cin >> str;
  for (int i = 1; i < str.size() - 1; i++) {
    if (str[i - 1] == str[i + 1] &&
        (getSG(0, i) ^ getSG(i + 1, str.size())) == 0) {
      cout << "First\n" << i + 1 << "\n";
      return 0;
    }
  }
  cout << "Second\n";
  return 0;
}
