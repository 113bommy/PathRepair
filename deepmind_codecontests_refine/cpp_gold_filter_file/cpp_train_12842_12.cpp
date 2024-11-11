#include <bits/stdc++.h>
using namespace std;
bool npr[10000001];
vector<int> pr;
int a, b, k;
void sf() {
  int sz = 0;
  int i;
  for (i = 2; i * i <= 10000000; i++) {
    if (!npr[i]) {
      pr.push_back(i);
      for (int j = i * i; j <= 10000000; j += i) npr[j] = true;
    }
  }
  for (; i < 10000000; i++)
    if (!npr[i]) pr.push_back(i);
}
int nxpr(int a, int n = 0) {
  return *(lower_bound(pr.begin(), pr.end(), a) + n);
}
int main() {
  cin >> a >> b >> k;
  sf();
  int maxx = lower_bound(pr.begin(), pr.end(), 1000000) - pr.begin();
  if (k > maxx) {
    cout << "-1\n";
    return 0;
  }
  int cpr = nxpr(a, k - 1);
  if (cpr > b) {
    cout << "-1\n";
    return 0;
  }
  int l = 0;
  for (cpr = a; cpr <= b; cpr++) {
    if (nxpr(cpr, k - 1) > b) {
      l = max(l, b + 2 - cpr);
      break;
    } else
      l = max(l, nxpr(cpr, k - 1) + 1 - cpr);
  }
  cout << l << endl;
  return 0;
}
