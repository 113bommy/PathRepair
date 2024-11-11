#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 100;
long long bestDev, cur;
int cntPos = 0, cntNeg;
int N, A[MAXN], cnt[MAXN], bestIdx;
int main() {
  scanf("%d", &N);
  for (int i = 0; i < (int)N; i++) scanf("%d", &A[i]), A[i]--;
  for (int i = 0; i < (int)N; i++) bestDev += abs(A[i] - i);
  for (int i = 0; i < (int)N; i++)
    if (A[i] - i >= 0) cnt[A[i] - i]++, cntPos++;
  cur = bestDev;
  cntNeg = N - cntPos;
  for (int i = 0; i < (int)N; i++) {
    if (cur < bestDev) {
      bestDev = cur;
      bestIdx = i;
    }
    cnt[A[N - i - 1] + i + 1]++;
    if (A[N - i - 1] - (N - i - 1) >= 0) cnt[A[N - i - 1] - (N - i - 1)]--;
    if (A[N - i - 1] - (N - i - 1) < i) cntPos++, cntNeg--;
    cntNeg += cnt[i];
    cntPos -= cnt[i];
    cur += cntNeg - cntPos + A[N - i - 1] - abs(A[N - i - 1] - (N - i - 1));
    if (A[N - i - 1] > N - i - 1)
      cur += (A[N - i - 1] - (N - i - 1) + 1) - (N - A[N - i - 1] - 1);
    else
      cur -= i - 1;
  }
  printf("%lld %d\n", bestDev, bestIdx);
}
