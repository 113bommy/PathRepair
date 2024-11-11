#include <bits/stdc++.h>
using namespace std;
int pn;
long long pri[10000000];
long long cnt[10000000];
set<pair<pair<long long, long long>, long long> > tree;
long long total = 0;
vector<long long> divis;
int main() {
  long long n;
  while (cin >> n) {
    tree.clear();
    if (n % 3LL != 0) {
    } else {
      n /= 3LL;
      divis.clear();
      for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) divis.push_back(i);
      }
      for (long long i = 0;
           divis[i] * divis[i] * divis[i] <= n && i < (int(divis.size()));
           i++) {
        for (long long j = i;
             divis[i] * divis[j] * divis[j] <= n && j < (int(divis.size()));
             j++) {
          if (n % (divis[j] * divis[i]) == 0) {
            long long k1 = divis[i], k2 = divis[j],
                      k3 = n / (divis[i] * divis[j]);
            if ((k1 + k2 + k3) % 2 == 0) {
              long long tl = (k1 + k2 + k3) / 2;
              if (k1 >= tl || k2 >= tl || k3 >= tl) continue;
              long long nu[3];
              nu[0] = tl - k1;
              nu[1] = tl - k2;
              nu[2] = tl - k3;
              if (nu[1] <= nu[0] && nu[1] <= nu[2]) swap(nu[0], nu[1]);
              if (nu[2] <= nu[0] && nu[2] <= nu[1]) swap(nu[0], nu[2]);
              if (nu[2] < nu[1]) swap(nu[1], nu[2]);
              tree.insert(make_pair(make_pair(nu[0], nu[1]), nu[2]));
            }
          }
        }
      }
    }
    total = 0;
    for (set<pair<pair<long long, long long>, long long> >::iterator itr =
             tree.begin();
         itr != tree.end(); ++itr) {
      long long a = itr->first.first;
      long long b = itr->first.second;
      long long c = itr->second;
      if (a == b && b == c) total++;
      if (a != b && b == c) total += 3;
      if (a == b && b != c) total += 3;
      if (a != b && b != c) total += 6;
    }
    cout << total << endl;
  }
  return 0;
}
