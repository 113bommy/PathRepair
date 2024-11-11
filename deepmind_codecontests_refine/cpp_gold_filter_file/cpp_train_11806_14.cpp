#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> ciel;
vector<int> attacks, defense;
char str[10];
int A, B, C;
bool done[110];
inline void ReadInput(void) {
  scanf("%d", &N);
  scanf("%d", &M);
  for (int i = 1; i <= N; i++) {
    scanf("%s", str);
    int a;
    scanf("%d", &a);
    if (str[0] == 'A') {
      attacks.push_back(a);
      A += a;
    } else {
      defense.push_back(a);
      B += a;
    }
  }
  for (int i = 1; i <= M; i++) {
    int a;
    scanf("%d", &a);
    ciel.push_back(a);
    C += a;
  }
}
int deleteall(void) {
  int curr = 0;
  fill(done, done + 110, false);
  for (int i = 0; i < defense.size(); i++) {
    while (curr < (int)ciel.size() and defense[i] >= ciel[curr]) {
      curr++;
    }
    if (curr == (int)ciel.size()) return 0;
    done[curr] = true;
    curr++;
  }
  int ret = 0;
  curr = 0;
  for (int i = 0; i < attacks.size(); i++) {
    while (curr < (int)ciel.size() and
           (done[curr] or attacks[i] > ciel[curr])) {
      if (!done[curr]) ret += (ciel[curr]);
      curr++;
    }
    if (curr == (int)ciel.size()) return 0;
    done[curr] = true;
    ret += (ciel[curr] - attacks[i]);
    curr++;
  }
  for (int i = curr; i < ciel.size(); i++)
    if (!done[i]) ret += (ciel[i]);
  return ret;
}
int select(int x) {
  int ret = 0;
  int curr = ciel.size() - 1;
  if (curr + 1 < x) return 0;
  for (int i = 0; i < x; i++) {
    if (attacks[i] > ciel[curr]) return 0;
    ret += (ciel[curr] - attacks[i]);
    curr--;
  }
  return ret;
}
int dontdelete(void) {
  int ret = 0;
  for (int i = 1; i <= attacks.size(); i++) ret = max(ret, select(i));
  return ret;
}
inline void solve(void) {
  sort(ciel.begin(), ciel.end());
  sort(attacks.begin(), attacks.end());
  sort(defense.begin(), defense.end());
  int a = 0, b = 0;
  a = dontdelete();
  b = deleteall();
  int ans = max(a, b);
  cout << ans;
}
inline void Refresh(void) {}
int main() {
  ios_base::sync_with_stdio(false);
  ReadInput();
  solve();
  return 0;
}
