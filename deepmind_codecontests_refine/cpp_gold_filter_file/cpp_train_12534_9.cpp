#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const long long LLINF = 9223372036854775807LL;
const int ST = 100010;
const int ST1 = 1000010;
const long long MOD = 1000000007;
long long ABS(long long a) {
  if (a < 0)
    return a * (-1);
  else
    return a;
}
long long mas[15];
vector<bool> prime(ST1, true);
vector<int> pr;
void gen() {
  prime[0] = false;
  prime[1] = false;
  for (int i = 2; i < 1010; i++) {
    if (prime[i]) {
      for (int j = i * i; j < ST1; j += i) {
        prime[j] = false;
      }
    }
  }
  for (int i = 0; i < ST1; i++) {
    if (prime[i]) pr.push_back(i);
  }
}
vector<vector<long long> > dd;
void razl(long long k) {
  vector<long long> t;
  for (int i = 0; i < (int)((pr).size()) && pr[i] <= k; i++) {
    while (k % pr[i] == 0) {
      k /= pr[i];
      t.push_back(pr[i]);
    }
  }
  if (k != 1) t.push_back(k);
  dd.push_back(t);
}
bool vhod[10];
int best = INF;
vector<vector<int> > msk;
vector<int> pp;
void gen(int l) {
  if ((int)((pp).size()) == l) {
    msk.push_back(pp);
  } else {
    pp.push_back(0);
    gen(l);
    pp.pop_back();
    pp.push_back(1);
    gen(l);
    pp.pop_back();
  }
}
int n;
void per(vector<long long> ost, vector<long long> raz, int num, int curans) {
  if (num == -1) {
    curans += n;
    if ((int)((raz).size()) > 1) curans++;
    best = min(best, curans);
    return;
  }
  vector<vector<int> > tt;
  vector<long long> pod;
  long long cur = ost[(int)((ost).size()) - 1];
  ost.pop_back();
  vector<long long> nevh;
  for (int i = 0; i < (int)((raz).size()); i++) {
    if (cur % raz[i] == 0 && cur != raz[i]) {
      pod.push_back(raz[i]);
    } else
      nevh.push_back(raz[i]);
  }
  msk.clear();
  gen((int)((pod).size()));
  tt = msk;
  for (int i = 0; i < (int)((tt).size()); i++) {
    long long tek = cur;
    vector<long long> dels = dd[num];
    vector<bool> good((int)((dels).size()));
    bool con = true;
    vector<long long> next = nevh;
    for (int j = 0; j < (int)((pod).size()) && con; j++) {
      if (tt[i][j] == 1) {
        long long val = pod[j];
        int uk = 0;
        for (int w = 0; w < n; w++) {
          if (val == mas[w]) {
            for (int r = 0; r < (int)((dd[w]).size()); r++) {
              while (uk < (int)((dels).size())) {
                if (dels[uk] == dd[w][r] && !good[uk]) {
                  good[uk] = true;
                  break;
                } else
                  uk++;
              }
              if (uk >= (int)((dels).size())) {
                con = false;
                break;
              }
              uk++;
            }
            if (uk > (int)((dels).size())) con = false;
            break;
          }
        }
      } else {
        next.push_back(pod[j]);
      }
    }
    if (!con) continue;
    int add = 0;
    for (int j = 0; j < (int)((good).size()); j++) {
      if (!good[j]) add++;
    }
    sort(next.begin(), next.end());
    if ((int)((dels).size()) == 1) add--;
    per(ost, next, num - 1, curans + add);
  }
}
int main() {
  cin >> n;
  gen();
  if (n == 1) {
    long long k;
    cin >> k;
    razl(k);
    if ((int)((dd[0]).size()) == 1) {
      cout << 1;
    } else {
      cout << (int)((dd[0]).size()) + 1;
    }
    return 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> mas[i];
  }
  sort(mas, mas + n);
  vector<long long> mm;
  for (int i = 0; i < n; i++) {
    razl(mas[i]);
    mm.push_back(mas[i]);
  }
  per(mm, mm, n - 1, 0);
  cout << best;
  return 0;
}
