#include <bits/stdc++.h>
using namespace std;
map<int, int> imap;
int main() {
  int n, k;
  scanf("%d", &n);
  scanf("%d", &k);
  for (int i = 0; i < n; i++) {
    int p;
    scanf("%d", &p);
    imap[p] = 1;
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    if (imap[i] == 0) {
      ans = i;
      break;
    }
  }
  if (ans > k) {
    printf("%d\n", 1);
  } else if (ans == k) {
    cout << 0 << endl;
  } else {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (imap[i] == 0) {
        if (i < k) {
          cnt++;
        }
      }
    }
    if (imap[k]) {
      cnt++;
    }
    printf("%d\n", cnt);
  }
}
