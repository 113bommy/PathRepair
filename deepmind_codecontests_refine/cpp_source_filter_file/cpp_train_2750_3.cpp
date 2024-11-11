#include <bits/stdc++.h>
int Freq[1000];
int main() {
  int n;
  scanf("%d", &n);
  int L[n];
  int count = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &L[i]);
    Freq[L[i]]++;
  }
  int max = Freq[0];
  for (int i = 0; i < 1000; i++) {
    if (Freq[i] > max) {
      max = Freq[i];
    }
    if (Freq[i] > 0) {
      count++;
    }
  }
  printf("%d %d\n", max, count);
}
