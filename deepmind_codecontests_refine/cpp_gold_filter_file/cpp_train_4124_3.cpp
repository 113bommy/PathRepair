#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, j, cnt = 0, cal = 0, flag = 0, temp;
  long long a[10005];
  set<long long> st;
  scanf("%I64d", &n);
  for (i = 0; i < n; i++) {
    scanf("%I64d", &a[i]);
    st.insert(a[i]);
  }
  if (st.size() == 1)
    printf("YES\n");
  else {
    for (i = 1; i < n; i++) {
      if (cal == 0) {
        if (a[i] > a[i - 1]) cnt++;
      }
      if (a[i] == a[i - 1])
        cal++;
      else if (a[i] < a[i - 1])
        break;
    }
    temp = cal + cnt;
    if (temp == 0) {
      for (j = temp; j < n - 1; j++) {
        if (a[j] <= a[j + 1]) {
          flag = 1;
          printf("NO\n");
          break;
        }
      }
    } else {
      for (j = temp; j < n - 1; j++) {
        if (a[j] <= a[j + 1]) {
          flag = 1;
          printf("NO\n");
          break;
        }
      }
    }
    if (flag == 0) printf("YES\n");
  }
  return 0;
}
