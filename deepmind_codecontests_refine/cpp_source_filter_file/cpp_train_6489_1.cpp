#include <bits/stdc++.h>
using namespace std;
int get_num(char*& p, int from, int to) {
  if (from == to) return p[from] - 48;
  if (p[from] == '0') return -1;
  int res = 0;
  for (int i = from; i <= to; i++) res = res * 10 + (p[i] - 48);
  return res;
}
int main() {
  char* s = new char[30];
  cin >> s;
  int len = strlen(s);
  int max = -1, ol = 0;
  for (int j = 1; j < len - 1 && j < 8; j++)
    for (int k = j + 1; k < len && k < j + 8; k++) {
      int o1 = get_num(s, 0, j - 1);
      int o2 = get_num(s, j, k - 1);
      int o3 = get_num(s, k, len - 1);
      if (len - 1 - k > 6) o3 = -1;
      if (o1 != -1 && o2 != -1 && o3 != -1) {
        ol = o1 + o2 + o3;
        if (ol > max && o1 < 1000000 && o2 < 1000000 && o3 < 1000000) max = ol;
      }
    }
  cout << max;
  delete[] s;
  return 0;
}
