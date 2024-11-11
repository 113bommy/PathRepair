#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e15;
void Tez() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  Tez();
  long long n, k;
  cin >> n >> k;
  long long cap[k];
  for (int i = 0; i < k; i++) cin >> cap[i];
  long long tp = 1, no = 0, maxam = 0;
  for (int i = 0; i < k; i++) {
    long long x = n / cap[i];
    long long am = x * cap[i];
    if (am > maxam) {
      no = x;
      maxam = am;
      tp = i + 1;
    }
  }
  cout << tp << " " << no;
  return 0;
}
