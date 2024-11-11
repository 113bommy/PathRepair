#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
char s1[maxn], s2[maxn], s3[maxn];
int n, t, sama, satu, dua;
int main() {
  scanf("%d %d", &n, &t);
  scanf("%s", s1);
  scanf("%s", s2);
  sama = satu = dua = 0;
  for (int i = 0; i < n; i++)
    if (s1[i] == s2[i]) sama++;
  int beda = n - sama;
  int half = 0;
  if (t >= beda) {
    int bedakan = t - beda;
    for (int i = 0; i < n; i++) {
      if (s1[i] == s2[i]) {
        if (bedakan) {
          s3[i] = s1[i] + 1;
          if (s3[i] > 'z') s3[i] == 'a';
          bedakan--;
          satu++;
          dua++;
        } else {
          s3[i] = s1[i];
        }
      } else if (s1[i] != s2[i]) {
        for (int j = 'a'; j <= 'z'; j++) {
          if (j != s1[i] && j != s2[i]) {
            s3[i] = j;
            break;
          }
        }
        satu++;
        dua++;
      }
    }
    if (bedakan > 0) {
      printf("-1\n");
      return 0;
    }
  } else if (t >= (int)floor((double)(beda + 1) / 2) && t < beda) {
    half = beda - t;
    half *= 2;
    for (int i = 0; i < n; i++) {
      if (s1[i] != s2[i]) {
        if (half) {
          if (half & 1) {
            s3[i] = s1[i];
            dua++;
          } else {
            s3[i] = s2[i];
            satu++;
          }
          half--;
        } else {
          for (int j = 'a'; j <= 'z'; j++) {
            if (j != s1[i] && j != s2[i]) {
              s3[i] = j;
              break;
            }
          }
          satu++;
          dua++;
        }
      } else {
        s3[i] = s1[i];
      }
    }
    if (half > 0) {
      printf("-1\n");
      return 0;
    }
  } else {
    printf("-1\n");
    return 0;
  }
  if (satu != t && dua != t)
    printf("-1\n");
  else
    printf("%s\n", s3);
  return 0;
}
