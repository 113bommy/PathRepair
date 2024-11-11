#include <bits/stdc++.h>
using namespace std;
long n;
long pr[10000];
vector<long> v;
set<long> has;
long ul;
long limm;
set<long>::iterator it;
long calc[100];
vector<long> v1;
long need[200];
void generate(long x) {
  has.insert(x);
  for (int j = 0; j < ul; j++) {
    if (x * v[j] <= limm && has.find(x * v[j]) == has.end()) {
      has.insert(x * v[j]);
      generate(x * v[j]);
    }
  }
}
bool check() {
  for (int j = 0; j < ul; j++) need[j] = (n + 1) / 2;
  for (int j = v1.size() - 1; j >= v1.size() - n; --j) {
    long mx, mp;
    mx = -1;
    mp = 0;
    for (int q = 0; q < ul; q++)
      if (need[q] > mx) {
        mx = need[q];
        mp = q;
      }
    if (v1[j] % v[mx]) continue;
    for (int q = 0; q < ul; q++)
      if (v1[j] % v[q] == 0) --need[q];
  }
  for (int i = 0; i < ul; i++)
    if (need[i] > 0) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  pr[1] = 1;
  for (int i = 2; i <= 1000; i++)
    if (pr[i] == 0)
      for (int j = i * 2; j <= 1000; j += i) pr[j] = 1;
  for (int i = 1; i <= 1000; i++)
    if (pr[i] == 0) v.push_back(i);
  cin >> n;
  limm = n * n * 2;
  for (int upp = 2; upp <= 10; upp++) {
    has.clear();
    ul = upp;
    generate(1);
    for (int j = 0; j < upp; j++) calc[j] = 0;
    if (has.size() >= n * 1.05) break;
    ;
    it = has.end();
    --it;
  }
  for (it = has.begin(); it != has.end(); ++it) {
    v1.push_back(*it);
  }
  for (int j = 0; j < ul; j++) need[j] = (n + 1) / 2;
  long done = 0;
  for (int j = v1.size() - 1; j >= 0; --j) {
    long mx, mp;
    mx = -1;
    mp = -1;
    for (int q = 0; q < ul; q++)
      if (need[q] > mx) {
        mx = need[q];
        mp = q;
      }
    if (mp > -1)
      if (v1[j] % v[mp]) continue;
    if (done < n) {
      cout << v1[j] << " ";
      ++done;
      for (int q = 0; q < ul; q++)
        if (v1[j] % v[q] == 0) --need[q];
    }
  }
  cout << endl;
  cin.get();
  cin.get();
  return 0;
}
