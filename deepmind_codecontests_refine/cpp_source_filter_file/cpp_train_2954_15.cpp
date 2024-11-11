#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
#pragma comment(linker, "/STACK:256000000")
const int D = 10000;
int mex(const vector<int> &a) {
  static bool used[D + 1] = {0};
  int c = (int)a.size();
  for (int i = 0; i < c; ++i)
    if (a[i] <= D) used[a[i]] = true;
  int result;
  for (int i = 0;; ++i)
    if (!used[i]) {
      result = i;
      break;
    }
  for (int i = 0; i < c; ++i)
    if (a[i] <= D) used[a[i]] = false;
  return result;
}
int main() {
  int n;
  scanf("%d", &n);
  long long *a = new long long[n];
  int res = 0;
  for (int i = 0; i < n; i++) {
    scanf("%I64d", a + i);
    int num;
    if (a[i] < 4)
      num = 0;
    else if (a[i] < 16)
      num = 1;
    else if (a[i] < 82)
      num = 2;
    else if (a[i] < 6724)
      num = 0;
    else if (a[i] < 50626)
      num = 3;
    else if (a[i] < 2562991877LL)
      num = 1;
    else
      num = 2;
    res ^= num;
  }
  if (res == 0) {
    cout << "Rublo" << endl;
  } else
    cout << "Furlo" << endl;
  return 0;
}
