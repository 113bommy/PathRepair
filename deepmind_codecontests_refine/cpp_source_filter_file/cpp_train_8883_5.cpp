#include <bits/stdc++.h>
using namespace std;
const int maxt = 100000, maxn = maxt + 7;
int h[7][7];
char s[5][maxn];
void output(int n) {
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= n; j++) printf("%c", s[i][j]);
    puts("");
  }
}
bool DoIt_2(int I, int n, int tot) {
  for (int i = 1; i <= n; i++)
    if (s[2][i] != s[I][i]) tot--;
  if (tot < 0) return false;
  if (tot == 0) return true;
  if (tot % 2 == 1) return false;
  vector<int> A, B;
  A.clear(), B.clear();
  for (int i = 1; i <= n; i++)
    if (s[2][i] == s[I][i]) {
      if (s[2][i] == 'a') A.push_back(i);
      if (s[2][i] == 'b') B.push_back(i);
    }
  for (int i = 0; i < min(A.size(), B.size()); i++) {
    int x = A[i], y = B[i];
    tot -= 2;
    swap(s[I][x], s[I][y]);
    if (tot == 0) return true;
  }
  return false;
}
bool DoIt_3(int I, int n, int tot) {
  for (int i = 1; i <= n; i++)
    if (s[3][i] != s[I][i]) tot--;
  if (tot < 0) return false;
  if (tot == 0) return true;
  if (tot % 2 == 1) return false;
  vector<int> AA, AB, BA, BB;
  AA.clear(), AB.clear(), BA.clear(), BB.clear();
  for (int i = 1; i <= n; i++)
    if (s[3][i] == s[I][i]) {
      if (s[2][i] == 'a' && s[3][i] == 'a') AA.push_back(i);
      if (s[2][i] == 'a' && s[3][i] == 'b') AB.push_back(i);
      if (s[2][i] == 'b' && s[3][i] == 'a') BA.push_back(i);
      if (s[2][i] == 'b' && s[3][i] == 'b') BB.push_back(i);
    }
  for (int i = 0; i < min(AA.size(), AB.size()); i++) {
    int x = AA[i], y = AB[i];
    tot -= 2;
    swap(s[I][x], s[I][y]);
    if (tot == 0) return true;
  }
  for (int i = 0; i < min(BA.size(), BB.size()); i++) {
    int x = BA[i], y = BB[i];
    tot -= 2;
    swap(s[I][x], s[I][y]);
    if (tot == 0) return true;
  }
  return false;
}
bool check(int n) {
  for (int i = 1; i <= 4; i++)
    for (int j = 1; j <= n; j++) s[i][j] = 'a';
  for (int i = 2; i <= 4; i++)
    for (int j = 1; j <= h[1][i]; j++) s[i][j] = 'b';
  for (int i = 3; i <= 4; i++)
    if (!DoIt_2(i, n, h[2][i])) return false;
  if (!DoIt_3(4, n, h[3][4])) return false;
  return true;
}
int main() {
  for (int i = 1; i <= 4; i++)
    for (int j = i + 1; j <= 4; j++) scanf("%d", &h[i][j]);
  int head = 1, tail = maxt;
  while (head <= tail) {
    int mid = (head + tail) / 2;
    if (check(mid))
      tail = mid - 1;
    else
      head = mid + 1;
  }
  int n = tail + 1;
  if (n > maxt) {
    puts("-1");
    return 0;
  }
  printf("%d\n", n);
  check(n);
  output(n);
}
