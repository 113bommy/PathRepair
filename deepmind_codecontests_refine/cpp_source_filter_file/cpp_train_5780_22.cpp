#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  tuple<long long, bool, long long> edge1[m];
  for (long long i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b;
    get<0>(edge1[i]) = a;
    get<1>(edge1[i]) = b;
    get<2>(edge1[i]) = i;
  }
  sort(edge1, edge1 + m);
  long long inT = 0, outT = 0, allow = 0;
  long long edge2[m];
  for (long long i = 0; i < m; i++) {
    if (get<1>(edge1[i]) == true) {
      inT++;
      allow += inT - 1;
    } else {
      outT++;
    }
    if (allow < outT) {
      cout << -1;
      return 0;
    }
    edge2[i] = inT;
  }
  pair<long long, long long> edge3[m];
  long long p1 = 1, p2 = 1, p3 = 2;
  for (long long i = 0; i < m; i++) {
    if (!get<1>(edge1[i])) {
      edge3[i].first = p2;
      edge3[i].second = p3;
      if (p2 == p3 - 1) {
        p3++;
        p2 = 1;
      } else {
        p2++;
      }
    } else {
      edge3[i].first = 0;
      edge3[i].second = p1;
      p1++;
    }
  }
  pair<long long, long long> edge4[m];
  for (long long i = 0; i < m; i++) {
    long long k = get<2>(edge1[i]);
    edge4[k].first = edge3[i].first;
    edge4[k].second = edge3[i].second;
  }
  for (long long i = 0; i < m; i++) {
    cout << edge4[i].first + 1 << " " << edge4[i].second + 1 << endl;
  }
}
