#include <bits/stdc++.h>
using namespace std;
int change(int day, int len, int s[], int pos, int we[]);
int n, day, we[1000], book[1000], res = 0, s[1000], len = 1;
int main() {
  cin >> n >> day;
  for (int i = 0; i < n; i++) cin >> we[i];
  for (int i = 0; i < day; i++) cin >> book[i];
  s[0] = book[0];
  for (int i = 1; i < day; i++) {
    int check = 0;
    for (int j = 0; j < len; j++)
      if (s[j] == book[i]) {
        check = 1;
        break;
      }
    if (!check) s[len++] = book[i];
  }
  for (int i = 1; i < day; i++) res += change(day, len, s, book[i], we);
  cout << res;
  return 0;
}
int change(int day, int len, int s[], int pos, int we[]) {
  int sum = 0, tmp[500], lens = 1;
  tmp[0] = pos;
  for (int i = 0; s[i] != pos; i++) {
    sum += we[s[i] - 1];
    tmp[lens++] = s[i];
  }
  for (int i = 0; i < lens; i++) s[i] = tmp[i];
  return sum;
}
