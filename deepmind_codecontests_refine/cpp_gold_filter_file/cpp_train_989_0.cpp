#include <bits/stdc++.h>
using namespace std;
int shu[1100000];
int sushu[110000];
long long dai[1100000];
long long ans;
int n;
long long a[1100000];
long long aa, bb;
int aaa, bbb;
map<long long, int> w1, wn;
int main() {
  for (int i = 2; i <= 1000000; i++) {
    if (!shu[i]) {
      for (int j = i * 2; j <= 1000000; j += i) shu[j] = 1;
    }
  }
  for (int i = 2; i <= 1000000; i++) {
    if (!shu[i]) {
      sushu[0]++;
      sushu[sushu[0]] = i;
    }
  }
  scanf("%d%d%d", &n, &aaa, &bbb);
  aa = aaa;
  bb = bbb;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    a[i] = x;
  }
  for (int i = 1; i <= sushu[0]; i++) {
    if (a[1] % sushu[i] == 0) w1[sushu[i]] = 1;
    if ((a[1] - 1) % sushu[i] == 0) w1[sushu[i]] = 1;
    if ((a[1] + 1) % sushu[i] == 0) w1[sushu[i]] = 1;
    w1[a[1]] = 1;
    w1[a[1] + 1] = 1;
    w1[a[1] - 1] = 1;
    if (a[n] % sushu[i] == 0) wn[sushu[i]] = 1;
    if ((a[n] - 1) % sushu[i] == 0) wn[sushu[i]] = 1;
    if ((a[n] + 1) % sushu[i] == 0) wn[sushu[i]] = 1;
    wn[a[n]] = 1;
    wn[a[n] - 1] = 1;
    wn[a[n] + 1] = 1;
  }
  sushu[0]++;
  sushu[sushu[0]] = a[1];
  sushu[0]++;
  sushu[sushu[0]] = a[1] + 1;
  sushu[0]++;
  sushu[sushu[0]] = a[n];
  sushu[0]++;
  sushu[sushu[0]] = a[n] + 1;
  sushu[0]++;
  sushu[sushu[0]] = a[1] - 1;
  sushu[0]++;
  sushu[sushu[0]] = a[n] - 1;
  ans = -1;
  for (int i = 1; i <= sushu[0]; i++) {
    if (sushu[i] == 1) continue;
    if ((!w1[sushu[i]]) && (!wn[sushu[i]])) {
    } else {
      long long q = sushu[i];
      for (int j = 1; j <= n; j++) {
        if (a[j] % q == 0) {
          dai[j] = 0;
        } else {
          if (((a[j] + 1) % q == 0) || ((a[j] - 1) % q == 0)) {
            dai[j] = bb;
          } else {
            dai[j] = aa * (long long)100;
          }
        }
      }
      int ji = 0;
      long long temp = 0;
      long long anss;
      for (int j = 2; j <= n; j++) dai[j] += dai[j - 1];
      anss = dai[n];
      for (int j = 1; j <= n; j++) {
        temp += dai[j] - dai[j - 1];
        ji++;
        if (temp >= (long long)ji * aa) {
          anss = min(anss, dai[j - ji] + dai[n] - dai[j] + (long long)ji * aa);
        } else {
          temp = 0;
          ji = 0;
        }
      }
      if (ans == -1) ans = anss;
      ans = min(ans, anss);
    }
  }
  cout << ans << endl;
  return 0;
}
