#include <bits/stdc++.h>
time_t waktu = clock();
void gettime() {
  printf("\nTime : %.2lf", (clock() - waktu) / double(CLOCKS_PER_SEC));
}
bool comp(int a, int b) { return (a > b); }
using namespace std;
int main() {
  int n, data[1005] = {1, 1}, i;
  scanf("%d", &n);
  for (i = 2; i <= n; i++) {
    data[i] = data[i - 1] * 3;
    data[i] %= 1000003;
  }
  printf("%d", data[n]);
  return 0;
}
