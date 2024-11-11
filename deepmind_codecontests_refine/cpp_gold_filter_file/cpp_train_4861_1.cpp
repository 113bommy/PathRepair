#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  char str[300001];
  long long left[300001], right[300001];
  long long res = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> str;
    int l = 0, r = 0;
    for (int i = 0; i < strlen(str); i++) {
      if (str[i] == '(')
        l++;
      else {
        if (l > 0)
          l--;
        else
          r++;
      }
    }
    if (l == 0 && r == 0)
      res++;
    else if (l != 0 && r == 0)
      left[l]++;
    else if (l == 0 && r != 0)
      right[r]++;
    else if (l != 0 && r != 0)
      continue;
  }
  res *= res;
  for (int i = 0; i <= 300001; i++) {
    if (left[i] > 0 && right[i] > 0) res += left[i] * right[i];
  }
  cout << res << endl;
  return 0;
}
