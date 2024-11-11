#include <bits/stdc++.h>
using namespace std;
vector<int> prime;
bool mark[10000001];
int minp[10000001];
vector<int> pa[664580], pb[664580];
void getPrime() {
  memset(minp, -1, sizeof(minp));
  for (int i = 2; i < 10000001; i++)
    if (!mark[i]) {
      prime.push_back(i);
      minp[i] = prime.size() - 1;
      for (int j = 2; i * j < 10000001; j++) {
        mark[i * j] = true;
        if (minp[i * j] == -1) minp[i * j] = prime.size() - 1;
      }
    }
}
int main() {
  getPrime();
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  vector<int> cnta(prime.size()), cntb(prime.size());
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = a[i]; j != 1;) {
      int t = minp[j], pr = prime[t];
      for (; j % pr == 0; j /= pr, cnta[t]++)
        ;
      pa[t].push_back(i);
    }
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    for (int j = b[i]; j != 1;) {
      int t = minp[j], pr = prime[t];
      for (; j % pr == 0; j /= pr, cntb[t]++)
        ;
      pb[t].push_back(i);
    }
  }
  for (int i = 0; i < prime.size(); i++) {
    int t = min(cnta[i], cntb[i]);
    int pr = prime[i], k = t;
    vector<int>::iterator it;
    for (it = pa[i].begin(); it != pa[i].end() && k; it++) {
      for (; a[*it] % pr == 0 && k; a[*it] /= pr, k--)
        ;
    }
    k = t;
    for (it = pb[i].begin(); it != pb[i].end() && k; it++) {
      for (; b[*it] % pr == 0 && k; b[*it] /= pr, k--)
        ;
    }
  }
  cout << a.size() << " " << b.size() << endl;
  for (int i = 0; i < a.size(); i++)
    printf("%d%c", a[i], i == a.size() - 1 ? '\n' : ' ');
  for (int i = 0; i < b.size(); i++)
    printf("%d%c", b[i], i == b.size() - 1 ? '\n' : ' ');
  return 0;
}
