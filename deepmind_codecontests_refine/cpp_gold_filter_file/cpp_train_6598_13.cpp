#include <bits/stdc++.h>
using namespace std;
int n;
int ar[2000000];
int used[2000000];
long long ans = 0;
int len(int a) {
  int ret = 0;
  while (a) {
    ret++;
    a /= 2;
  }
  return ret;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) ar[i] = i;
  for (int i = n; i >= 0; i--) {
    int tmp = (1 << len(i)) - 1;
    cerr << "``" << tmp << endl;
    tmp = tmp ^ i;
    cerr << i << "~>" << tmp << endl;
    if (tmp > i || i == 0) continue;
    reverse(&ar[tmp], &ar[i + 1]);
    i = tmp;
  }
  for (int i = 0; i <= n; i++) ans += i ^ ar[i];
  cout << ans << endl;
  for (int i = 0; i <= n; i++) cout << ar[i] << " ";
}
