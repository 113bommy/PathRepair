#include <bits/stdc++.h>
using namespace std;
long long int l[200000], r[200000];
int main() {
  long long int n;
  cin >> n;
  for (long long int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
  }
  sort(l, l + n);
  sort(r, r + n);
  long long int left = 0, right = 0;
  long long int cnt = 0;
  while (cnt <= 2) {
    if (left == n) break;
    if (l[left] <= r[right]) {
      left++;
      cnt++;
    } else {
      right++;
      cnt--;
    }
  }
  if (cnt <= 2)
    printf("YES");
  else
    printf("NO");
  return 0;
}
