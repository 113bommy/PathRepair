#include <bits/stdc++.h>
using namespace std;
pair<int, int> tst[100005];
int rep[100005];
int idx[100005];
int arr[100005];
pair<int, int> sw[1000000];
int ns;
int num, id;
int islucky(int x) {
  for (; x > 0; x /= 10)
    if (x % 10 != 4 and x % 10 != 7) return 0;
  return 1;
}
int main() {
  int i, j;
  int a, b, c, d;
  int n;
  ns = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    tst[i] = pair<int, int>(arr[i], i);
  }
  sort(tst, tst + n);
  for (i = 0; i < n; i++) {
    rep[i] = tst[i].first;
    idx[i] = tst[i].second;
    arr[tst[i].second] = i;
  }
  num = -1;
  for (i = 0; i < n; i++) {
    if (islucky(rep[i])) {
      num = i;
      id = idx[i];
      break;
    }
  }
  if (num == -1) {
    for (i = 0; i < n - 1; i++)
      if (arr[i] > arr[i + 1]) {
        printf("-1\n");
        return 0;
      }
  }
  for (i = 0; i < n; i++) {
    if (i == num or i == arr[i]) continue;
    a = i;
    b = id;
    c = idx[i];
    d = arr[i];
    if (a != b) sw[ns++] = pair<int, int>(a, b);
    if (a != c) sw[ns++] = pair<int, int>(a, c);
    idx[num] = id = c;
    idx[i] = a;
    idx[arr[i]] = b;
    swap(arr[a], arr[b]);
    swap(arr[a], arr[c]);
  }
  printf("%d\n", ns);
  for (i = 0; i < ns; i++) printf("%d %d\n", sw[i].first + 1, sw[i].second + 1);
  return 0;
}
