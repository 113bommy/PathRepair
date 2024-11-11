#include <bits/stdc++.h>
using namespace std;
long long white_max[8], black_max[8];
long long white_min[8], black_min[8];
int main() {
  memset(black_min, 0x3f, sizeof black_min);
  memset(white_min, 0x3f, sizeof white_min);
  long long A = 1000000LL;
  long long B = 1000000LL;
  for (long long i = 0; i < 8; i++) {
    for (long long j = 0; j < 8; j++) {
      char c;
      scanf(" %c", &c);
      if (c == 'B') {
        black_max[j] = max(black_max[j], i);
        black_min[j] = min(black_min[j], i);
      } else if (c == 'W') {
        white_max[j] = max(white_max[j], i);
        white_min[j] = min(white_min[j], i);
      }
    }
  }
  for (long long j = 0; j < 8; j++) {
    if (black_max[j] > white_max[j]) B = min(B, 8 - black_max[j] - 1);
    if (white_min[j] < black_min[j]) A = min(A, white_min[j]);
  }
  if (B >= A)
    puts("A");
  else
    puts("B");
}
