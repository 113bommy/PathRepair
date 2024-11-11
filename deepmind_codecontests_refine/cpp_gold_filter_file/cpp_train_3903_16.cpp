#include <bits/stdc++.h>
using namespace std;
long long x, s;
int v[2];
void val() {
  v[0] = 4;
  v[1] = 7;
  s = 0;
}
vector<long long> a;
void ql(long long i) {
  for (int j = 0; j <= 1; j++) {
    s = s * 10 + v[j];
    if (i == x) {
      a.push_back(s);
    } else
      ql(i + 1);
    s = s / 10;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(0);
  val();
  long long ans = 0;
  long long n;
  cin >> n;
  for (x = 1; x <= 10; x++) ql(1);
  for (int i = 0; i < a.size(); i++)
    if (a[i] >= n) {
      ans = i + 1;
      break;
    }
  cout << ans;
  return 0;
}
