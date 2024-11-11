#include <bits/stdc++.h>
using namespace std;
int s[200010], h[200010];
int check(int first, int last, int val) {
  if (first == last || last == first + 1) {
    return min(fabs(h[first] - val), fabs(h[last] - val));
  }
  int mid = (first + last) / 2;
  if (h[mid] < val) {
    return check(mid + 1, last, val);
  } else if (h[mid] > val) {
    return check(first, mid - 1, val);
  }
}
int main() {
  int n;
  while (cin >> n) {
    memset(h, 0, sizeof(h));
    int m = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &s[i]);
      if (s[i] == 0) {
        h[m++] = i;
      }
    }
    for (int i = 0; i < n; i++) {
      if (s[i] != 0) {
        s[i] = check(0, m - 1, i);
      }
    }
    for (int i = 0; i < n - 1; i++) {
      printf("%d ", s[i]);
    }
    cout << s[n - 1] << endl;
  }
  return 0;
}
