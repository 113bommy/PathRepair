#include <bits/stdc++.h>
using namespace std;
int a[100010], cnt[10010];
int main() {
  int n;
  cin >> n;
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  bool flag = 0;
  for (int i = 0; i < n; i++) {
    if (cnt[a[i]] % 2 == 1) {
      flag = true;
      break;
    }
  }
  if (flag)
    cout << "Conan" << endl;
  else
    cout << "Agasa" << endl;
  return 0;
}
