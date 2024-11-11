#include <bits/stdc++.h>
using namespace std;
long long int modulo = 1000000009;
int h;
long long int expo2[31];
long long int expo3[31];
long long int expo4[31];
long long int memmaneres0[1001];
long long int maneres0(int n) {
  long long int &mem = memmaneres0[n];
  if (mem != -1) return mem;
  mem = 0;
  if (n < h) {
    mem = expo4[n] % modulo;
    return mem;
  }
  for (int t = 1; t <= h; t++)
    mem = (mem + expo3[t - 1] * maneres0(n - t)) % modulo;
  return mem;
}
long long int memmaneres1[1001][31];
long long int maneres1(int n, int i) {
  long long int &mem = memmaneres1[n][i];
  if (mem != -1) return mem;
  mem = 0;
  if (n < h) {
    mem = expo3[i - 1] * expo4[n - i] % modulo;
    return mem;
  }
  for (int t = 1; t <= h; t++) {
    if (t < i)
      mem = (mem + expo2[t - 1] * maneres1(n - t, i - t)) % modulo;
    else if (t > i)
      mem = (mem + expo2[i - 1] * maneres1(n - i, t - i)) % modulo;
  }
  return mem;
}
long long int memmaneres2[1001][31][31];
long long int maneres2(int n, int i, int j) {
  long long int &mem = memmaneres2[n][i][j];
  if (mem != -1) return mem;
  mem = 0;
  if (n < h) {
    mem = expo2[i - 1] * expo3[j - i - 1] % modulo * expo4[n - j] % modulo;
    return mem;
  }
  for (int t = 1; t <= h; t++) {
    if (t < i)
      mem = (mem + maneres2(n - t, i - t, j - t)) % modulo;
    else if (t > i and t < j)
      mem = (mem + maneres2(n - i, t - i, j - i)) % modulo;
    else if (t > j)
      mem = (mem + maneres2(n - i, j - i, t - i)) % modulo;
  }
  return mem;
}
long long int memmaneres3[1001][31][31][31];
long long int maneres3(int n, int i, int j, int k) {
  long long int &mem = memmaneres3[n][i][j][k];
  if (mem != -1) return mem;
  mem = 0;
  if (n < h) {
    mem = expo2[j - i - 1] * expo3[k - j - 1] % modulo * expo4[n - k] % modulo;
    return mem;
  }
  if (i > 1) {
    mem = maneres3(n - 1, i - 1, j - 1, k - 1);
  } else {
    for (int t = i + 1; t <= h; t++) {
      if (t < j)
        mem = (mem + maneres3(n - i, t - i, j - i, k - i)) % modulo;
      else if (t > j and t < k)
        mem = (mem + maneres3(n - i, j - i, t - i, k - i)) % modulo;
      else if (t > k)
        mem = (mem + maneres3(n - i, j - i, k - i, t - i)) % modulo;
    }
  }
  return mem;
}
int main() {
  for (int n = 0; n < 1001; n++)
    for (int i = 0; i < 31; i++)
      for (int j = 0; j < 31; j++)
        for (int k = 0; k < 31; k++) memmaneres3[n][i][j][k] = -1;
  for (int n = 0; n < 1001; n++)
    for (int i = 0; i < 31; i++)
      for (int j = 0; j < 31; j++) memmaneres2[n][i][j] = -1;
  for (int n = 0; n < 1001; n++)
    for (int i = 0; i < 31; i++) memmaneres1[n][i] = -1;
  for (int n = 0; n < 1001; n++) memmaneres0[n] = -1;
  expo2[0] = expo3[0] = expo4[0] = 1;
  for (int i = 1; i < 31; i++) {
    expo2[i] = (2 * expo2[i - 1]) % modulo;
    expo3[i] = (3 * expo3[i - 1]) % modulo;
    expo4[i] = (4 * expo4[i - 1]) % modulo;
  }
  int n;
  cin >> n >> h;
  long long int r = 0;
  for (int i = 0; i < h; i++)
    r += expo3[i] * maneres0(n - i - 1) % modulo * 4 % modulo;
  for (int i = 0; i < h; i++)
    for (int j = i + 1; j < h; j++)
      r -= expo2[i] * maneres1(n - i - 1, j - i) % modulo * 12 % modulo;
  for (int i = 0; i < h; i++)
    for (int j = i + 1; j < h; j++)
      for (int k = j + 1; k < h; k++)
        r += maneres2(n - i - 1, j - i, k - i) % modulo * 24 % modulo;
  for (int i = 1; i < h; i++)
    for (int j = i + 1; j < h; j++)
      for (int k = j + 1; k < h; k++)
        r -= maneres3(n - 1, i, j, k) % modulo * 24 % modulo;
  r = (r + modulo) % modulo;
  cout << r << endl;
}
