#include <bits/stdc++.h>
using namespace std;
const int inf = (1 << 30) - 1;
const long double eps = 1e-9;
const long double pi = fabs(atan2(0.0, -1.0));
int *ass;
void ML() {
  for (;;) {
    ass = new int[2500000];
    for (int i = 0; i < 2500000; i++) ass[i] = rand();
  }
}
struct node {
  int num;
  int cost;
};
bool operator<(const node &a, const node &b) {
  if (a.cost != b.cost) return a.cost > b.cost;
  return a.num > b.num;
}
int n, k;
long long gold;
node a[100500], b[100500];
bool was[100500];
void LoAd() {
  scanf("%d%d", &n, &k);
  cin >> gold;
  for (int i = 0; i < n; i++) {
    a[i].num = i;
    scanf("%d", &a[i].cost);
    b[i] = a[i];
  }
  sort(b, b + n - 1);
}
void SoLvE() {
  for (int i = 0; i < k - 1; i++) {
    gold -= b[i].cost;
    was[b[i].num] = true;
    if (gold < 0) {
      printf("1");
      return;
    }
  }
  int best_place = n;
  for (int i = 0; i < n; i++) {
    if (was[i]) {
      best_place = i;
      break;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[i].cost > gold && !was[i]) {
      best_place = min(best_place, i);
      printf("%d", best_place + 1);
      return;
    }
  }
  printf("%d", n);
  return;
}
int main() {
  srand((int)time(NULL));
  LoAd();
  SoLvE();
  return 0;
}
