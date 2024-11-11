#include <bits/stdc++.h>
using namespace std;
long long int n, Money, Dollars[1024], A_Money;
void Read() {
  long long int i;
  scanf("%I64d %I64d", &n, &Money);
  for (i = 0; i < n; i++) scanf("%I64d", &Dollars[i]);
}
void Play() {
  long long int i, j, Cost = 0, DD;
  A_Money = Money;
  for (i = 0; i < n; i++) {
    Cost = Money % Dollars[i];
    DD = Money / Dollars[i];
    for (j = i + 1; j < n; j++)
      if (Cost + DD * Dollars[j] > A_Money) A_Money = Cost + DD * Dollars[j];
  }
  printf("%I64d\n", A_Money);
}
int main() {
  Read();
  Play();
  return 0;
}
