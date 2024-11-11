#include <bits/stdc++.h>
using namespace std;
const int MAX = 500001;
struct para {
  int a, b;
};
inline bool cmp(para a, para b) { return a.b < b.b; }
int n, l, cnt;
para arr[MAX];
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i].a >> arr[i].b;
  sort(arr, arr + n, cmp);
  int i = 0;
  while (i < n) {
    cnt++;
    l = arr[i].b;
    while (l >= arr[i].a && i < n) ++i;
  }
  cout << cnt;
  return 0;
}
