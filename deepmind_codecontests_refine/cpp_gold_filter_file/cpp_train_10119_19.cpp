#include <bits/stdc++.h>
using namespace std;
int n, k, a, permu[8] = {0, 1, 2, 3, 4, 5, 6, 7};
vector<vector<int> > digit;
long b, jwb = 1000000000;
void masuk() {
  long num[8], g, maks = 0, mini = 1000000000;
  for (int i = 0; i < n; i++) {
    g = 0;
    for (int j = k - 1; j >= 0; j--) g = g * 10 + digit[i][permu[j]];
    num[i] = g;
  }
  for (int i = 0; i < n; i++) {
    if (mini > num[i]) mini = num[i];
    if (maks < num[i]) maks = num[i];
  }
  if (abs(maks - mini) < jwb) jwb = abs(maks - mini);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%ld", &b);
    digit.push_back(vector<int>());
    for (int j = 0; j < k; j++) {
      digit[i].push_back(b % 10);
      b /= 10;
    }
  }
  do {
    masuk();
  } while (next_permutation(permu, permu + k));
  printf("%ld\n", jwb);
  return 0;
}
