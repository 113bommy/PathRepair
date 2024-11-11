#include <bits/stdc++.h>
using namespace std;
int n, k;
long long s[211111], mx[211111];
int a[211111], bg[211111];
long long hf, ans;
int bhf, aa, bb;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    s[i] = s[i - 1] + a[i];
  }
  for (int i = k; i <= n; ++i) {
    if (s[i] - s[i - k] > mx[i - 1]) {
      mx[i] = s[i] - s[i - k];
      bg[i] = i - k + 1;
    } else
      mx[i] = mx[i - 1], bg[i] = bg[i - 1];
  }
  hf = 0;
  for (int i = n - k + 1; i >= 1; --i) {
    if (mx[i] + hf >= ans) {
      long long tmp = ans;
      ans = mx[i] + hf;
      if (tmp < ans) aa = bg[i], bb = bhf;
      if (bg[i] < aa || (bg[i] == aa && bhf < bb)) {
        aa = bg[i], bb = bhf;
      }
    }
    if (s[i + k - 1] - s[i - 1] >= hf) {
      hf = s[i + k - 1] - s[i - 1];
      bhf = i;
    }
  }
  cout << aa << " " << bb << endl;
}
