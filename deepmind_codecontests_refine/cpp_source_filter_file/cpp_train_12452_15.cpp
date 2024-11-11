#include <bits/stdc++.h>
using namespace std;
string mem_s;
int n;
int arr[1000000];
map<int, int> used;
bool check(int val) {
  used.clear();
  string s = mem_s;
  int cur_pos = -10000000;
  int way = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '*') {
      if (arr[i] < n && !used[arr[i]]) {
        if (arr[i] - i <= val) {
          for (int j = i; j < arr[i]; j++) s[j] = '.';
          way = arr[i] - i;
          int buf_way = val - way;
          int p = arr[i];
          while (buf_way - 2 >= 0 && p + 1 < n) {
            buf_way -= 2;
            p++;
            if (s[p] != 'P')
              s[p] = '.';
            else
              break;
          }
          buf_way = val - way * 2;
          p = arr[i];
          while (buf_way - 1 >= 0 && p + 1 < n) {
            buf_way -= 1;
            p++;
            if (s[p] != 'P')
              s[p] = '.';
            else
              break;
          }
          used[arr[i]] = 1;
        } else
          return false;
      } else
        return false;
    }
    if (s[i] == 'P' && !used[i]) {
      way = 0;
      cur_pos = i;
      while (way + 1 <= n && cur_pos + 1 < n) {
        way++;
        cur_pos++;
        if (s[cur_pos] != 'P')
          s[cur_pos] = '.';
        else
          break;
      }
    }
  }
  return true;
}
int main() {
  cin >> n;
  cin >> mem_s;
  int l = 0, r = n * 2;
  int pos = 100000000;
  for (int i = n - 1; i >= 0; i--) {
    arr[i] = pos;
    if (mem_s[i] == 'P') pos = i;
  }
  while (l != r) {
    int mid = (r + l) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  cout << l;
}
