#include <bits/stdc++.h>
using namespace std;
pair<int, int> cars[105][105];
int K[105];
int main() {
  int N, S;
  scanf("%d", &N);
  ;
  scanf("%d", &S);
  ;
  for (int i = 0; i < N; i++) {
    scanf("%d", &K[i]);
    ;
    int total = 0;
    for (int j = 0; j < K[i]; j++) {
      int a, b;
      scanf("%d", &a);
      ;
      scanf("%d", &b);
      ;
      total += b;
      cars[i][j] = make_pair(total, a);
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++)
    for (int j = i + 1; j < N; j++) {
      int last = 0;
      int distA = 0;
      int distB = 0;
      int speedA = cars[i][0].second;
      int speedB = cars[j][0].second;
      bool A = false;
      bool B = false;
      int ia = 0;
      int ib = 0;
      while (ia < K[i] && ib < K[j]) {
        if (cars[i][ia].first < cars[j][ib].first) {
          int shift = cars[i][ia].first - last;
          distA += speedA * shift;
          distB += speedB * shift;
          if (distA > distB) {
            if (B) {
              ans++;
            }
            A = true;
            B = false;
          } else if (distA < distB) {
            if (A) {
              ans++;
            }
            B = true;
            A = false;
          }
          last += shift;
          ia++;
          if (ia < K[i]) speedA = cars[i][ia].second;
        } else if (cars[i][ia].first > cars[j][ib].first) {
          int shift = cars[j][ib].first - last;
          distA += speedA * shift;
          distB += speedB * shift;
          if (distA > distB) {
            if (B) {
              ans++;
            }
            A = true;
            B = false;
          } else if (distA < distB) {
            if (A) {
              ans++;
            }
            B = true;
            A = false;
          }
          last += shift;
          ib++;
          if (ib < K[j]) speedB = cars[j][ib].second;
        } else {
          int shift = cars[j][ib].first - last;
          distA += speedA * shift;
          distB += speedB * shift;
          if (distA > distB) {
            if (B) ans++;
            A = true;
            B = false;
          }
          if (distA < distB) {
            if (A) ans++;
            B = true;
            A = false;
          }
          last += shift;
          ib++;
          if (ib < K[j]) speedB = cars[j][ib].second;
          ia++;
          if (ia < K[i]) speedA = cars[i][ia].second;
        }
      }
    }
  printf("%d\n", ans);
}
