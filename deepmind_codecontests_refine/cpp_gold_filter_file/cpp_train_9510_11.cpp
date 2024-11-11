#include <bits/stdc++.h>
using namespace std;
int num[100005];
int main() {
  int n;
  scanf("%d", &n);
  int flag = 0, cnt, Mini, Min = 1000000002;
  for (int i = 0; i < n; i++) {
    scanf("%d", &cnt);
    num[i] = cnt;
    if (Min > cnt) Mini = i;
    Min = min(cnt, Min);
  }
  for (int i = 0; i < n; i++) {
    if (Mini != i && Min == num[i]) flag = 1;
  }
  if (flag)
    printf("Still Rozdil");
  else
    cout << Mini + 1;
  return 0;
}
