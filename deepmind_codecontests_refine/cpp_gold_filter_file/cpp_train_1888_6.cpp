#include <bits/stdc++.h>
using namespace std;
const int Maxq = 500005;
int q;
char qa[Maxq];
int qb[Maxq];
vector<int> un;
long long BIT[Maxq];
multiset<int> S;
void Insert(int ind, long long sum) {
  ind++;
  for (int i = ind; i < Maxq; i += i & -i) BIT[i] += sum;
}
long long Get(int ind) {
  ind++;
  long long res = 0;
  for (int i = ind; i > 0; i -= i & -i) res += BIT[i];
  return res;
}
int main() {
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf(" %c %d", &qa[i], &qb[i]);
    un.push_back(qb[i]);
  }
  sort(un.begin(), un.end());
  un.erase(unique(un.begin(), un.end()), un.end());
  for (int i = 0; i < q; i++) {
    int ind = lower_bound(un.begin(), un.end(), qb[i]) - un.begin();
    if (qa[i] == '+') {
      Insert(ind, qb[i]);
      S.insert(qb[i]);
    } else {
      Insert(ind, -qb[i]);
      multiset<int>::iterator it = S.find(qb[i]);
      S.erase(it);
    }
    if (S.empty())
      printf("0\n");
    else {
      int res = 0;
      long long got = *S.begin();
      while (true) {
        if (2 * got > 1000000000) break;
        int ind =
            upper_bound(un.begin(), un.end(), int(2 * got)) - un.begin() - 1;
        long long ngot = Get(ind);
        if (got == ngot) {
          multiset<int>::iterator it = S.upper_bound(2 * got);
          if (it == S.end()) break;
          int ind = upper_bound(un.begin(), un.end(), *it) - un.begin() - 1;
          got = Get(ind);
          res++;
        } else
          got = ngot;
      }
      printf("%d\n", int(S.size()) - 1 - res);
    }
  }
  return 0;
}
