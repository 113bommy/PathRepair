#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1000005;
char buffer[MAX_N];
int bits[MAX_N];
void read_bits(int bits[], int &n) {
  scanf("%s", buffer);
  for (n = 0; buffer[n] != '\0'; n++) bits[n] = (int)(buffer[n] - '0');
  reverse(bits, bits + n);
}
bool find_chunks(int bits[], int n, int &i, int &j) {
  while (i < n && bits[i] != 1) i++;
  if (bits[i] != 1) return false;
  j = i;
  while (bits[j + 1] == 1) j++;
  return true;
}
int count_bits(int bits[], int n) {
  int ans = 0;
  for (int i = 0; i <= n; i++) ans += (bits[i] != 0);
  return ans;
}
int main() {
  int n;
  read_bits(bits, n);
  int i = 0, j = 0;
  while (find_chunks(bits, n, i, j)) {
    if (j - i + 1 > 2) {
      for (int k = i; k <= j; k++) bits[k] = 0;
      bits[i] = -1;
      bits[j + 1] = 1;
    }
    i += 2;
  }
  printf("%d\n", count_bits(bits, n));
  for (int i = 0; i <= n; i++) {
    if (bits[i] == 1)
      printf("+2^%d\n", i);
    else if (bits[i] == -1)
      printf("-2^%d\n", i);
  }
  return 0;
}
