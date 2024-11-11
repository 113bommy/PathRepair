#include <bits/stdc++.h>
using namespace std;
const int MAX = 51, MAXWEIGHT = 500001;
bool bag[MAX][MAXWEIGHT];
int n, d, c[MAX];
int main() {
  scanf("%d%d", &n, &d);
  for (int i = (1); i <= (n); ++i) {
    scanf("%d", &c[i]);
  }
  for (int pos = (1); pos <= (n); ++pos) {
    for (int weight = (0); weight <= (MAXWEIGHT); ++weight) {
      if (pos == 1) {
        if (weight == 0 || weight == c[pos]) {
          bag[pos][weight] = 1;
        } else {
          bag[pos][weight] = 0;
        }
      } else {
        if (c[pos] > weight) {
          bag[pos][weight] = bag[pos - 1][weight];
        } else {
          bag[pos][weight] =
              bag[pos - 1][weight] | bag[pos - 1][weight - c[pos]];
        }
      }
    }
  }
  vector<int> bag_list;
  for (int w = (0); w <= (MAXWEIGHT); ++w) {
    if (bag[n][w]) bag_list.push_back(w);
  }
  sort(bag_list.begin(), bag_list.end());
  int max_weight = 0, step = 0, pos = 0;
  while (pos < bag_list.size()) {
    int j = pos + 1;
    while (j < bag_list.size() && bag_list[pos] + d >= bag_list[j]) ++j;
    if (pos == j - 1) break;
    ++step;
    pos = j - 1;
    max_weight = bag_list[pos];
  }
  printf("%d %d\n", max_weight, step);
  return 0;
}
