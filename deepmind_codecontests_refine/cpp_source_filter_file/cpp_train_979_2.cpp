#include <bits/stdc++.h>
using namespace std;
const int MX = 101;
vector<int> ip;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  int a1 = 0, a2 = 0;
  for (int i = 0; i < N; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int a;
      cin >> a;
      if (j < k / 2)
        a1 += a;
      else if (j >= (k + 1) / 2)
        a2 += a;
      else
        ip.push_back(a);
    }
  }
  sort(ip.begin(), ip.end());
  reverse(ip.begin(), ip.end());
  for (int i = 0; i < (int)ip.size(); i++) {
    if (not i & 1)
      a1 += ip[i];
    else
      a2 += ip[i];
  }
  cout << a1 << ' ' << a2 << endl;
  return 0;
}
