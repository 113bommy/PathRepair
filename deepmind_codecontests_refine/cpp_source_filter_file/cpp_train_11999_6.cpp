#include <bits/stdc++.h>
using namespace std;
int e1[100001];
int e0[100001];
int l1[100001];
int l0[100001];
int main() {
  std::ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  int n = s.size();
  int num1 = 0, num0 = 0, num2 = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      num1 += 1;
    } else if (s[i] == '0') {
      num0 += 1;
    } else {
      num2 += 1;
    }
  }
  bool flag[4] = {false, false, false, false};
  if (n % 2 == 0) {
    if (num0 + num2 - num1 >= 2) flag[0] = true;
    if (num1 + num2 - num0 >= 2) flag[3] = true;
    if (num0 <= n / 2 && num1 <= n / 2) {
      int a = n / 2 - num0, b = n / 2 - num1;
      int last[2][2] = {{-1, -1}, {-1, -1}};
      int need[2][2] = {{a, b}, {a, b}};
      for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
          if (last[0][0] == -1) last[0][0] = i;
          if (last[1][0] == -1) last[1][0] = i;
        } else if (s[i] == '1') {
          if (last[0][1] == -1) last[0][1] = i;
          if (last[1][1] == -1) last[1][1] = i;
        } else {
          if (need[0][0] > 0) {
            need[0][0]--;
            if (last[0][0] == -1) last[0][0] = i;
          } else if (need[0][1] > 0) {
            need[0][1]--;
            if (last[0][1] == -1) last[0][1] = i;
          }
          if (need[1][1] > 0) {
            need[1][1]--;
            if (last[1][1] == -1) last[1][1] = i;
          } else if (need[1][0] > 0) {
            need[1][0]--;
            if (last[1][0] == -1) last[1][0] = i;
          }
        }
      }
      if (last[0][0] > last[0][1]) flag[2] = true;
      if (last[1][1] > last[1][0]) flag[1] = true;
    }
  } else {
    if (num0 + num2 - num1 >= 1) flag[0] = true;
    if (num1 + num2 - num0 >= 3) flag[3] = true;
    if (num0 <= n / 2 && num1 <= n / 2 + 1) {
      int a = n / 2 - num0, b = n / 2 - num1;
      int last[2][2] = {{-1, -1}, {-1, -1}};
      int need[2][2] = {{a, b}, {a, b}};
      for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
          if (last[0][0] == -1) last[0][0] = i;
          if (last[1][0] == -1) last[1][0] = i;
        } else if (s[i] == '1') {
          if (last[0][1] == -1) last[0][1] = i;
          if (last[1][1] == -1) last[1][1] = i;
        } else {
          if (need[0][0] > 0) {
            need[0][0]--;
            if (last[0][0] == -1) last[0][0] = i;
          } else if (need[0][1] > 0) {
            need[0][1]--;
            if (last[0][1] == -1) last[0][1] = i;
          }
          if (need[1][1] > 0) {
            need[1][1]--;
            if (last[1][1] == -1) last[1][1] = i;
          } else if (need[1][0] > 0) {
            need[1][0]--;
            if (last[1][0] == -1) last[1][0] = i;
          }
        }
      }
      if (last[0][0] > last[0][1]) flag[2] = true;
      if (last[1][1] > last[1][0]) flag[1] = true;
    }
  }
  if (flag[0]) cout << "00" << endl;
  if (flag[1]) cout << "01" << endl;
  if (flag[2]) cout << "10" << endl;
  if (flag[3]) cout << "11" << endl;
  return 0;
}
