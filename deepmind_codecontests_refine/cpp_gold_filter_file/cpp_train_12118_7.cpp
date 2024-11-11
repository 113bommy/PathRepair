#include <bits/stdc++.h>
using namespace std;
const int MAXLEN = 105;
int findmin(int *ceil, bool *visited, int len, int target) {
  for (int i = 0; i < len; i++) {
    if (visited[i] == false && (ceil[i] >= target)) {
      visited[i] = true;
      return i;
    }
  }
  return -1;
}
int killatk(const int &n, const int &m, int &lenatk, int &lendef, int &lenciel,
            int *atk, int *def, int *ceil) {
  int sum = 0;
  int len = min(lenatk, lenciel);
  for (int i = 0; i < len; i++) {
    sum += max(0, (ceil[lenciel - 1 - i] - atk[i]));
  }
  return sum;
}
int killall(const int &n, const int &m, int &lenatk, int &lendef, int &lenciel,
            int *atk, int *def, int *ceil) {
  int sum = 0;
  bool visited[MAXLEN];
  memset(visited, false, MAXLEN * sizeof(bool));
  if (lendef > lenciel) return sum;
  for (int i = 0; i < lendef; i++) {
    int idx = findmin(ceil, visited, lenciel, def[i] + 1);
    if (idx < 0) return 0;
  }
  for (int i = 0; i < lenatk; i++) {
    int idx = findmin(ceil, visited, lenciel, atk[i]);
    if (idx < 0) return sum;
    sum += (ceil[idx] - atk[i]);
  }
  for (int i = 0; i < lenciel; i++) {
    if (visited[i] == false) sum += ceil[i];
  }
  return sum;
}
void input(const int &n, const int &m, int &lenatk, int &lendef, int &lenciel,
           int *atk, int *def, int *ceil) {
  char pos[4];
  for (int i = 0; i < n; i++) {
    scanf("%s", pos);
    if (pos[0] == 'A')
      scanf("%d", &atk[lenatk++]);
    else
      scanf("%d", &def[lendef++]);
  }
  for (int i = 0; i < m; i++) scanf("%d", &ceil[lenciel++]);
}
int main() {
  int n, m;
  int atk[MAXLEN], def[MAXLEN], ceil[MAXLEN];
  int lenatk, lendef, lenciel;
  int score;
  while (~scanf("%d%d", &n, &m)) {
    lenatk = lendef = lenciel = 0;
    input(n, m, lenatk, lendef, lenciel, atk, def, ceil);
    sort(atk, atk + lenatk);
    sort(def, def + lendef);
    sort(ceil, ceil + lenciel);
    int s1 = killatk(n, m, lenatk, lendef, lenciel, atk, def, ceil);
    int s2 = killall(n, m, lenatk, lendef, lenciel, atk, def, ceil);
    score = max(s1, s2);
    printf("%d\n", score);
  }
  return 0;
}
