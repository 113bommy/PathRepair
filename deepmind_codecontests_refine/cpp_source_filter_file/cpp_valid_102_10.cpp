#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
const int N = 1 << 16, K = 1 << 6;
int k, A, h;
int ran[K + 5];
int power[K + 5];
map<int, vector<int> > rev[2], ver[2];
deque<int> q;
int main() {
  cin >> k >> A >> h;
  power[0] = 1;
  for (int i = 1; i < (1 << k); i++) power[i] = 1ll * power[i - 1] * A % P;
  for (int i = 0; i < 1 << (1 << (k - 1)); i++) {
    q.clear();
    int mask = i;
    for (int j = 1; j <= (1 << (k - 1)); j++)
      ran[j] = (1 << (k - 1)), q.push_back(j);
    while (q.size() > 1) {
      int first = q.front();
      q.pop_front();
      int second = q.front();
      q.pop_front();
      if (mask & 1)
        ran[second] >>= 1, q.push_back(second), mask >>= 1;
      else
        ran[first] >>= 1, q.push_back(first), mask >>= 1;
    }
    int sum = 0;
    vector<int> ans;
    for (int j = 1; j <= (1 << (k - 1)); j++)
      sum = (sum + 1ll * j * power[ran[j] + 1] % P) % P,
      ans.push_back(ran[j] + 1);
    int ed = q.back();
    rev[0][sum] = ans;
    sum = (sum - 1ll * ed * power[ans[ed - 1]] % P + P) % P;
    ans[ed - 1]--;
    rev[1][(sum + 1ll * ed * power[ans[ed - 1]] % P) % P] = ans;
  }
  vector<int> all;
  for (int i = 0; i < 1 << (1 << (k - 1)); i++) {
    q.clear();
    int mask = i;
    for (int j = 1 + (1 << (k - 1)); j <= (1 << k); j++)
      ran[j] = (1 << (k - 1)), q.push_back(j);
    while (q.size() > 1) {
      int first = q.front();
      q.pop_front();
      int second = q.front();
      q.pop_front();
      if (mask & 1)
        ran[second] >>= 1, q.push_back(second), mask >>= 1;
      else
        ran[first] >>= 1, q.push_back(first), mask >>= 1;
    }
    int sum = 0;
    vector<int> ans;
    for (int j = 1 + (1 << (k - 1)); j <= (1 << k); j++)
      sum = (sum + 1ll * j * power[ran[j] + 1] % P) % P,
      ans.push_back(ran[j] + 1);
    int ed = q.back();
    if (rev[1].count((h - sum + P) % P)) {
      all = rev[1][(h - sum + P) % P];
      all.insert(all.end(), ans.begin(), ans.end());
      break;
    }
    sum = (sum - 1ll * ed * power[ans[ed - 1 - (1 << (k - 1))]] % P + P) % P;
    ans[ed - 1 - (1 << (k - 1))]--;
    (sum += 1ll * ed * power[ans[ed - 1 - (1 << (k - 1))]] % P) %= P;
    if (rev[0].count((h - sum + P) % P)) {
      all = rev[0][(h - sum + P) % P];
      all.insert(all.end(), ans.begin(), ans.end());
      break;
    }
  }
  if (all.empty())
    cout << "-1" << endl;
  else {
    for (int i = 0; i < (1 << k); i++) cout << all[i] << " ";
    cout << endl;
  }
  return 0;
}
