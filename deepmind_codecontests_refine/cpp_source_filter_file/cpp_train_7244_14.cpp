#include <bits/stdc++.h>
using namespace std;
template <typename T>
using pq_gt = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using pq_lt = priority_queue<T, vector<T>, less<T>>;
map<int, int> cnt;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cnt.clear();
    int n = 250;
    bool pois = 0;
    long long int sum = 0;
    int maxi = 0;
    int mini = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      maxi = max(maxi, x);
      mini = min(mini, x);
      sum += x;
      if (x > 2000) {
        pois = 1;
      } else {
        cnt[x]++;
      }
    }
    sum = round((double)sum / (double)n);
    long long int s1 = 0;
    long long int s2 = 0;
    int dev = 1.3 * sqrt(maxi);
    for (int i = sum - dev; i <= sum + dev; i++) {
      s1 += cnt[i];
    }
    s2 = long long int(2 * dev + 1) * long long int(n) /
             (long double)(maxi - mini + 1) +
         20;
    if (s1 > s2) {
      pois = 1;
    } else {
      pois = 0;
    }
    if (pois)
      cout << "poisson" << endl;
    else
      cout << "uniform" << endl;
  }
}
