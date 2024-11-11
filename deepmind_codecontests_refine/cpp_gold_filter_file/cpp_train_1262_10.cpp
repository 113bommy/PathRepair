#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e17 + 2;
const int maxn = 1e5 + 10;
const int maxq = 1e3 + 10;
const int alf = 26;
const int dlm = 1e9 + 7;
const long long mod = 998244353;
string O[] = {"YES", "NO", "Yes", "No"};
vector<long long> ans;
int main() {
  long long n;
  cin >> n;
  long long x = sqrt(n);
  long long sum = n * (n + 1) / 2;
  for (int k = 1; k <= x; k++) {
    if (n % k != 0) continue;
    long long y = (sum - (n / k) * ((k - 1) * k / 2)) / k;
    ans.push_back(y);
    long long g = n / k;
    long long z = (sum - (n / g) * ((g - 1) * g / 2)) / g;
    ans.push_back(z);
  }
  sort(ans.begin(), ans.end());
  long long Oops = -1;
  for (int i = 0; i < ans.size(); i++) {
    if (Oops == ans[i]) continue;
    Oops = ans[i];
    cout << " " << Oops;
  }
}
