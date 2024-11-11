#include <bits/stdc++.h>
int main() {
  long long int answer = 0;
  int first_number, second_number;
  int i;
  scanf("%d%d", &first_number, &second_number);
  for (i = 1; i <= first_number; i++) {
    answer += (second_number + i % 5) / 5;
  }
  printf("%lld\n", answer);
}
