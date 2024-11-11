#include <bits/stdc++.h>
using namespace std;
const int N = 600005;
int a[N];
long long int s, cnt[N] = {0};
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i] = a[i] - i + 200005;
  }
  for (int i = 0; i < n; i++) {
    cnt[a[i]] += a[i] - 200005 + i;
  }
  for (int i = 0; i < n; i++) {
    s = max(s, cnt[a[i]]);
  }
  cout << s;
}
