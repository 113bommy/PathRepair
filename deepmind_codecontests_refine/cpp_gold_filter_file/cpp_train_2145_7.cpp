#include <bits/stdc++.h>
using namespace std;
const int maxn = 10050;
int a[maxn], b[maxn];
bool cmp(int a, int b) { return a > b; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  while (cin >> n >> k) {
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < k; i++) {
      cin >> b[i];
    }
    sort(b, b + n, cmp);
    int tmp = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) {
        a[i] = b[tmp++];
      }
    }
    bool flag = false;
    for (int i = 1; i < n; i++) {
      if (a[i] - a[i - 1] < 0) {
        flag = true;
        break;
      }
    }
    if (flag) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
