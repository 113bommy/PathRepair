#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:666000000")
using namespace std;
const int INF = (1 << 30) - 1;
const long double EPS = 1e-9;
void ML(const bool v) {
  if (v) return;
  int *ass;
  for (;;) {
    ass = new int[2500000];
    for (int i = 0; i < 2500000; i++) ass[i] = rand();
  }
}
void TL(const bool v) {
  if (v) return;
  for (;;) cout << rand() % (rand() % 1000 + 1) << endl;
}
void PE(const bool v) {
  if (v) return;
  for (int i = 0; i < 10000; i++) printf("%c", rand() % 256);
  exit(0);
}
int n;
char _tmp[100500];
string s, t;
bool LoAd() {
  if (1 != scanf("%s", _tmp)) return false;
  s = _tmp;
  cin >> t;
  return true;
}
int cnt[300];
string res;
bool go(const int v) {
  if (v >= (int)s.size()) return false;
  if (v >= (int)t.size()) return true;
  if (0 != cnt[t[v]]) {
    res.push_back(t[v]);
    cnt[t[v]]--;
    if (go(v + 1)) {
      for (int i = 'a'; i <= 'z'; i++) {
        while (cnt[i] > 0) {
          cnt[i]--;
          res.push_back(i);
        }
      }
      return true;
    }
    res.pop_back();
    cnt[t[v]]++;
  }
  for (int i = t[v] + 1; i <= 'z'; i++) {
    if (cnt[i] > 0) {
      cnt[i]--;
      res.push_back(i);
      for (int j = 'a'; j <= 'z'; j++) {
        while (cnt[j] > 0) {
          cnt[j]--;
          res.push_back(j);
        }
      }
      return true;
    }
  }
  return false;
}
void SoLvE() {
  res.clear();
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < (int)s.size(); i++) cnt[s[i]]++;
  if (!go(0))
    puts("-1");
  else
    printf("%s\n", res.c_str());
}
int main() {
  srand((int)time(NULL));
  LoAd();
  SoLvE();
  return 0;
}
