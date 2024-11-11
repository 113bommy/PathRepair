#include <bits/stdc++.h>
using namespace std;
int bases[40 + 1], tails[40 + 1];
int minLen, maxLen;
int log2(long long n) {
  if (n <= 1) return (int)n;
  return 1 + log2(n >> 1);
}
bool calc() {
  for (int i = 2; i <= 40; i++) {
    if (bases[i] > bases[i - 1]) {
      tails[i - 1] += bases[i] - bases[i - 1];
      bases[i] = bases[i - 1];
    }
  }
  for (int i = 40; i > 0; i--) {
    if (!tails[i]) continue;
    if (bases[i] < tails[i]) return false;
    for (int j = 1; j <= i; j++) {
      bases[j] -= tails[i];
    }
    minLen += tails[i];
    for (int j = i + 1; tails[i] > 0 && j <= 40; j++) {
      tails[i] = max(bases[j], tails[i]);
      bases[j] -= tails[i];
    }
  }
  maxLen = minLen + bases[1];
  int tailFree = bases[1];
  int currBase = 1;
  while (tailFree > 0) {
    for (int i = currBase + 1; i <= 40; i++) {
      if (bases[i] == bases[currBase])
        currBase++;
      else
        break;
    }
    if (tailFree - 1 >= currBase) {
      tailFree -= currBase + 1;
      bases[currBase]--;
    } else
      break;
  }
  minLen += bases[currBase];
  return true;
}
int main() {
  int n;
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) {
    long long ai;
    scanf("%lld", &ai);
    int order = log2(ai);
    if (ai == 1LL << (order - 1))
      bases[order]++;
    else
      tails[order]++;
  }
  if (!calc()) {
    printf("-1\n");
  } else {
    for (int i = minLen; i <= maxLen; i++) printf("%d ", i);
    printf("\n");
  }
  return 0;
}
