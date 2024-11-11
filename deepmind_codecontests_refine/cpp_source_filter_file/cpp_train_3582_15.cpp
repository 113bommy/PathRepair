#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;
int n, a[MAXN], cnt[MAXN], cnt1[MAXN], add[MAXN];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n * 2; ++i) {
    scanf("%d", &a[i]);
    ++cnt[a[i]];
  }
  int Kurumi = 0, Yoshino = 0;
  for (int i = 10; i <= 99; ++i)
    if (cnt[i] == 1)
      ++Kurumi;
    else if (cnt[i] > 0)
      ++Yoshino;
  int Tohka = 0;
  if (Kurumi & 1)
    Tohka = (Kurumi / 2 + Yoshino) * (Kurumi / 2 + 1 + Yoshino);
  else
    Tohka = (Kurumi / 2 + Yoshino) * (Kurumi / 2 + Yoshino);
  cout << Tohka << endl;
  int Houki = Kurumi & 1;
  Kurumi = 0;
  for (int i = 1; i <= n * 2; ++i) {
    if (cnt[a[i]] == 1) {
      printf("%d ", (Kurumi & 1) + 1);
      ++Kurumi;
    } else {
      if ((cnt[a[i]] & 1) && !cnt1[a[i]]) {
        add[a[i]] = Houki & 1;
        ++Houki;
      }
      printf("%d ", ((cnt1[a[i]] + add[a[i]]) & 1) + 1);
    }
    ++cnt1[a[i]];
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
