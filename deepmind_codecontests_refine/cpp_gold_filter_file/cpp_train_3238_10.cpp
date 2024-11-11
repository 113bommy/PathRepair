#include <bits/stdc++.h>
using namespace std;
int amount;
int numbers[200005];
int zero[200005], mem = 0;
int smallest = -(int)1e9 - 5, spot = 0;
int smaller_zero = 0;
int mark[200005];
void print_result() {
  int start = 1;
  for (int i = 1; i <= amount; i++) {
    if (mark[i]) continue;
    mark[i] = 1;
    while (mark[start] && start <= amount) start++;
    if (start > amount) return;
    printf("1 %d %d\n", i, start);
  }
}
void special() {
  int run = 0;
  if (!mem && smaller_zero % 2 == 0) return;
  for (int i = 1; i < mem; i++) {
    printf("1 %d %d\n", zero[i], zero[i + 1]);
    run++;
    mark[zero[i]] = 1;
  }
  int erase_spot = 0;
  if (smaller_zero % 2 == 0)
    erase_spot = zero[mem];
  else if (mem == 0)
    erase_spot = spot;
  else {
    printf("1 %d %d\n", zero[mem], spot);
    run++;
    mark[zero[mem]] = 1;
    erase_spot = spot;
  }
  if (run != amount - 1) printf("2 %d\n", erase_spot);
  mark[erase_spot] = 1;
}
void solve() {
  special();
  print_result();
}
int main() {
  scanf("%d", &amount);
  for (int i = 1; i <= amount; i++) {
    scanf("%d", &numbers[i]);
    if (numbers[i] == 0)
      zero[++mem] = i;
    else if (numbers[i] < 0) {
      smaller_zero++;
      if (smallest < numbers[i]) {
        smallest = numbers[i];
        spot = i;
      }
    }
  }
  solve();
}
