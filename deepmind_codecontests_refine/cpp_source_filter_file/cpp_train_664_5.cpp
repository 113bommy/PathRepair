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
string s;
vector<string> a;
string ser = "<3";
bool LoAd() {
  if (!(1 == scanf("%d", &n))) return false;
  a.resize(n);
  for (int i = 0; i < (int)(n); i++) cin >> a[i];
  cin >> s;
  return true;
}
struct node {};
void SoLvE() {
  string t;
  t.reserve(100500);
  t += ser;
  for (int i = 0; i < (int)(n); i++) t += a[i] + ser;
  int j = 0;
  for (int i = 0; i < (int)(t.size()); i++) {
    while (j < (int)s.size() && s[j] != t[i]) j++;
    if (j == (int)s.size()) {
      puts("no");
      return;
    }
  }
  puts("yes");
}
int main() {
  srand((int)time(NULL));
  LoAd();
  SoLvE();
  return 0;
}
