#include <bits/stdc++.h>
using namespace std;
struct perem {
  long long t = 0, l = 1, p = -1, q = 0;
};
ifstream fin("AAtest.in.txt");
long long n, k, m, c, vas, cc = 1000000;
vector<long long> vv;
string s;
vector<vector<long long>> la;
vector<perem> pr;
int main() {
  ios::sync_with_stdio(0);
  fin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  fin >> n >> k >> s;
  la.resize(n, vector<long long>(0));
  pr.resize(k);
  for (int(i) = (0); ((i)) < ((k)); ((i))++) {
    fin >> m;
    for (int(j) = (0); ((j)) < ((m)); ((j))++) {
      fin >> c;
      la[c - 1].emplace_back(i);
    }
  }
  for (int(i) = (0); ((i)) < ((n)); ((i))++) {
    vas = 0;
    if (la[i].size() > 0) {
      long long a = la[i][0];
      bool b1 = 0;
      while (a != -1) {
        b1 ^= pr[a].q;
        if (pr[a].p != -1)
          a = pr[a].p;
        else
          break;
      }
      if (la[i].size() == 1) {
        if ((b1 and s[i] == '1') or (!b1 and s[i] == '0')) {
          vas += pr[a].l;
          pr[a].q ^= 1;
        }
        pr[a].l = cc;
      } else {
        long long b = la[i][1];
        bool b2 = 0;
        while (b != -1) {
          b2 ^= pr[b].q;
          if (pr[b].p != -1)
            b = pr[b].p;
          else
            break;
        }
        if (a != b) {
          b1 ^= b2;
          long long kl = 0;
          if ((b1 and s[i] == '1') or (!b1 and s[i] == '0')) {
            if (pr[a].l < pr[b].l) {
              vas += pr[a].l;
              pr[a].q ^= 1;
            } else {
              vas += pr[b].l;
              pr[b].q ^= 1;
            }
            kl = abs(pr[a].l - pr[b].l);
          } else
            kl = min(pr[a].l + pr[b].l, cc);
          if (pr[a].t < pr[b].t) swap(a, b);
          if (pr[a].q) pr[b].q ^= 1;
          if (pr[a].t == pr[b].t) pr[a].t++;
          pr[a].l = kl;
          pr[b].p = a;
        }
      }
    }
    if (i)
      vv.emplace_back(vv.back() + vas);
    else
      vv.emplace_back(vas);
  }
  for (long long i : vv) cout << i << endl;
}
