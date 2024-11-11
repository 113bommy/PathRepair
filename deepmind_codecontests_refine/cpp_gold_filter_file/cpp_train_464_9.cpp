#include <bits/stdc++.h>
using namespace std;
int main() {
  int tb[100001] = {-1};
  int t[100001];
  int tn = 0;
  int n, k;
  int a;
  int first;
  cin >> n >> k;
  int re = 0;
  for (int i = 0; i < k; i++) {
    cin >> a;
    cin >> first;
    re += (a - 1) * 2;
    t[tn] = first;
    tn++;
    for (int j = 1; j < a; j++) {
      cin >> t[tn];
      tb[first] = t[tn];
      first = t[tn];
      tn++;
    }
  }
  re += k - 1;
  sort(t, t + tn);
  for (int i = 0; i < tn - 1; i++) {
    if (t[i + 1] != tb[t[i]]) break;
    re -= 2;
  }
  cout << re;
  return 0;
}
