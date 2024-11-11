#include <bits/stdc++.h>
using namespace std;
int n, arr[105], mem[105][4];
int mnrst(int i, int prevact) {
  if (i == n) return 0;
  int &ret = mem[i][-1 * prevact];
  if (ret != -1) return ret;
  ret = 1E9;
  if (arr[i] == 0) return ret = min(ret, 1 + mnrst(i + 1, -3));
  if (arr[i] == 1) {
    if (prevact != -2) ret = min(ret, mnrst(i + 1, -2));
    ret = min(ret, 1 + mnrst(i + 1, -3));
  }
  if (arr[i] == 2) {
    if (prevact != -1) ret = min(ret, mnrst(i + 1, -1));
    ret = min(ret, 1 + mnrst(i + 1, -3));
  }
  if (arr[i] == 3) {
    if (prevact != -1) ret = min(ret, mnrst(i + 1, -1));
    if (prevact != -2) ret = min(ret, mnrst(i + 1, -2));
    ret = min(ret, 1 + mnrst(i + 1, -3));
  }
  return ret;
}
int main() {
  cin >> n;
  memset(mem, -1, sizeof(mem));
  for (int i = 0; i < n; i++) scanf("%i", arr + i);
  cout << mnrst(0, 0);
  return 0;
}
