#include <bits/stdc++.h>
using namespace std;
int n, a[200005], mx;
vector<char> V;
char L = 'L', R = 'R';
void input() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  return;
}
void output() {
  cout << V.size() << endl;
  for (int i = 0; i < V.size(); i++) cout << V[i];
  return;
}
void ezclap() {
  int l = 1, r = n;
  if (a[l] < a[r]) {
    V.push_back(L);
    mx = a[l];
    l++;
  } else {
    V.push_back(R);
    mx = a[r];
    r--;
  }
  while (l < r) {
    if (a[l] < a[r]) {
      if (a[l] > mx) {
        V.push_back(L);
        mx = a[l];
        l++;
      } else if (a[r] > mx) {
        V.push_back(R);
        mx = a[r];
        r--;
      } else
        return;
    } else {
      if (a[r] > mx) {
        V.push_back(R);
        mx = a[r];
        r--;
      } else if (a[l] > mx) {
        V.push_back(L);
        mx = a[l];
        l++;
      } else
        return;
    }
  }
  if (l == r && a[l] > mx) V.push_back(R);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  {
    input();
    ezclap();
    output();
  }
  return 0;
}
