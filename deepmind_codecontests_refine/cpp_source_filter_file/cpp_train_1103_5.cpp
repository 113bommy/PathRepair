#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long a;
  string n;
  cin >> a >> n;
  long long tot = 0;
  for (char i : n) {
    int val = i - '0';
    tot += val;
  }
  sort(n.rbegin(), n.rend());
  int re = 0;
  for (int i = n.size() - 1; i >= 0; i--) {
    if (tot >= a) break;
    int val = 9 - (n[i] - '0');
    tot += 9 - val;
    re++;
  }
  cout << re;
}
