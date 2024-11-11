#include <bits/stdc++.h>
using namespace std;
bool status[1000005];
vector<int> pal, prime;
bool check_palin(int n) {
  if (n < 10) return true;
  vector<int> temp;
  int a, i, j;
  while (n) {
    a = n % 10;
    temp.push_back(a);
    n /= 10;
  }
  i = 0, j = temp.size() - 1;
  while (i < j) {
    if (temp[i] != temp[j]) {
      return false;
    }
    i++, j--;
  }
  return true;
}
int main() {
  int i, j, p, q, si;
  si = int(sqrt((double)1000005));
  for (i = 3; i <= si; i += 2) {
    for (j = i * i; j <= 1000005; j += i + i) {
      status[j] = true;
    }
  }
  prime.push_back(2);
  for (i = 3; i <= 1000005; i += 2) {
    if (!status[i]) {
      prime.push_back(i);
    }
  }
  for (i = 1; i <= 1000005; i++) {
    if (check_palin(i)) {
      pal.push_back(i);
    }
  }
  vector<int>::iterator up;
  scanf("%d %d", &p, &q);
  int ans = -1;
  for (i = 1; i <= 1000000; i++) {
    up = upper_bound(prime.begin(), prime.end(), i);
    int prime_num = up - prime.begin();
    if (i == 1) prime_num = 0;
    up = upper_bound(pal.begin(), pal.end(), i);
    int pal_num = up - pal.begin();
    if (q * prime_num <= p * pal_num) {
      ans = i;
    }
  }
  if (ans == -1)
    printf("Palindromic tree is better than splay tree\n");
  else
    printf("%d\n", ans);
  return 0;
}
