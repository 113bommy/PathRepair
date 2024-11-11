#include <bits/stdc++.h>
int p = 3;
int q = 1e9 + 7;
char str[1000005];
long long int hash_prefix[1000005];
long long int T[1000005];
int ans[500010];
void hash() {
  hash_prefix[0] = 0;
  int size = strlen(str);
  T[0] = 1;
  for (int i = 1; i <= size; i++) {
    hash_prefix[i] = (hash_prefix[i - 1] * p + str[i - 1]) % q;
    T[i] = (T[i - 1] * p) % q;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", str);
  hash();
  int size = strlen(str);
  int k = 1 + ((size - 1) >> 1);
  int ct = k;
  int r = size / 2, l;
  int length = -1;
  if (size & 1)
    l = r;
  else
    l = r - 1;
  while (l >= 0) {
    if (r == size / 2) {
      if (size & 1)
        ;
      else if (str[l] == str[r])
        length += 2;
    } else {
      int temp_length = length;
      while (temp_length > -3) {
        long long int hash_left =
            (hash_prefix[l + temp_length + 2] -
             hash_prefix[l] * T[temp_length + 2] % q + q) %
            q;
        long long int hash_right =
            (hash_prefix[r + 1] -
             hash_prefix[r - temp_length - 1] * T[temp_length + 2] % q + q) %
            q;
        if (hash_left == hash_right) break;
        temp_length -= 2;
      }
      length = temp_length + 2;
    }
    ans[k--] = length;
    l--;
    r++;
  }
  for (k = 1; k <= ct; k++) printf("%d ", ans[k]);
}
