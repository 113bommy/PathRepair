#include <bits/stdc++.h>
using namespace std;
constexpr long long int inf = 1000000000000000000;
constexpr long long int mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(12) << fixed;
  constexpr long long int photos = 1000001;
  long long int n;
  cin >> n;
  vector<long long int> count(photos), last_like(photos);
  for (long long int i = 0; i != n; ++i) {
    long long int tmp;
    cin >> tmp;
    ++count[tmp];
    last_like[tmp] = i;
  }
  long long int best = 1;
  for (long long int i = 1; i != photos; ++i)
    if (count[i] > count[best])
      best = i;
    else if (count[i] == count[best])
      if (last_like[i] < last_like[best]) best = i;
  cout << best << endl;
  return 0;
}
