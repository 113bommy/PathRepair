#include <bits/stdc++.h>
using namespace std;
int amount, swaps;
int numbers[200005], allowed_swaps[200005];
bool is_good() {
  for (int i = 2; i <= amount; i++) {
    if (numbers[i] > numbers[i - 1]) continue;
    int start = i;
    while (numbers[start] < numbers[start - 1]) {
      if (allowed_swaps[start - 1])
        swap(numbers[start], numbers[start - 1]);
      else
        return false;
      start--;
    }
  }
  return true;
}
void solve() {
  scanf("%d %d", &amount, &swaps);
  for (int i = 1; i <= amount; i++) scanf("%d", &numbers[i]);
  for (int i = 1; i <= amount; i++) allowed_swaps[i] = 0;
  for (int i = 1; i <= swaps; i++) {
    int spot;
    scanf("%d", &spot);
    allowed_swaps[spot] = 1;
  }
  if (is_good())
    printf("YES\n");
  else
    printf("NO\n");
}
int main() {
  int tester;
  scanf("%d", &tester);
  while (tester--) solve();
}
