#include <bits/stdc++.h>
using namespace std;
const int maxi = 3e5;
long long rez;
set<int> st[maxi];
long long bit[maxi];
int a[maxi], b[maxi];
int n;
void update(int x, int val) {
  for (int k = x; k < maxi; k += k & (-k)) bit[k] += val;
}
int get(int x) {
  int ans = 0;
  for (int k = x; k > 0; k -= k & (-k)) ans += bit[k];
  return ans;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i];
    st[a[i]].insert(i);
  }
  sort(b + 1, b + n + 1);
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    int val = b[i];
    int poz = 0;
    if (st[val].lower_bound(cur) == st[val].end())
      poz = *st[val].begin();
    else
      poz = *st[val].lower_bound(cur);
    if (poz > cur) {
      rez += poz - cur;
      rez -= (get(poz) - get(cur));
    } else {
      rez += n - cur + poz;
      rez -= get(n) - (get(cur) - get(poz));
    }
    cur = poz;
    update(poz, 1);
    st[val].erase(poz);
  }
  cout << rez << "\n";
  return 0;
}
