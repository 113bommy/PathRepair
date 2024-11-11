#include <bits/stdc++.h>
using namespace std;
struct node {
  int data;
  int pos;
};
int ans[205];
node a[205];
int aa[105], bb[105];
int vt[100];
bool cmp(node a, node b) { return a.data < b.data; }
int main() {
  int n;
  cin >> n;
  int i;
  for (i = 0; i < 2 * n; i++) {
    scanf("%d", &a[i].data);
    a[i].pos = i;
    vt[a[i].data]++;
  }
  sort(a, a + 2 * n, cmp);
  int flag = 0;
  int ct[2] = {0, 0};
  for (i = 0; i < 2 * n; i++) {
    int t = vt[a[i].data];
    if (t == 1) {
      ans[a[i].pos] = flag + 1;
      ct[flag]++;
      flag = 1 - flag;
    }
    if (t >= 2) {
      ans[a[i].pos] = 1;
      ans[a[i + 1].pos] = 2;
      ct[0]++;
      ct[1]++;
      while (i != (2 * n - 1) && a[i + 1].data == a[i].data) {
        i++;
      }
    }
  }
  cout << ct[0] * ct[1] << endl;
  for (i = 0; i < 2 * n; i++) {
    if (ans[i] != 0) continue;
    ans[a[i].pos] = flag + 1;
    flag = 1 - flag;
  }
  for (i = 0; i < 2 * n; i++) {
    if (i) cout << " ";
    cout << ans[i];
  }
  return 0;
}
