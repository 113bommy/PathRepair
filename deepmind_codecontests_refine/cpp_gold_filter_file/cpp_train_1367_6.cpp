#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
long long l[MAXN];
char input[MAXN];
int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%I64d", &l[i]);
  scanf("%s", input);
  long long answer = 0;
  long long energy = 0, twicegrass = 0, water = 0;
  bool existwater = false;
  for (int i = 0; i < n; i++) {
    switch (input[i]) {
      case 'G':
        answer += 5LL * l[i];
        energy += l[i];
        twicegrass += 2LL * l[i];
        break;
      case 'W':
        energy += l[i];
        answer += 3LL * l[i];
        water += l[i];
        existwater = true;
        break;
      case 'L':
        answer += l[i];
        if (energy >= l[i])
          energy -= l[i];
        else {
          if (existwater)
            answer += 3LL * (l[i] - energy);
          else
            answer += 5LL * (l[i] - energy);
          energy = 0;
        }
        break;
    }
    twicegrass = min(twicegrass, energy);
  }
  answer -= (5LL - 1LL) * twicegrass / 2;
  answer -= (3LL - 1LL) * min(water, energy - twicegrass) / 2;
  printf("%I64d\n", answer);
  return 0;
}
