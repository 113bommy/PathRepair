#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[100];
  for (int i = 0; i < n; i++) cin >> a[i];
  int num[101] = {0};
  for (int i = 0; i < n; i++) num[a[i]]++;
  int cnt = 0;
  for (int i = 1; i <= 100; i++) cnt += num[i] / 2;
  cout << cnt / 2 << endl;
}
