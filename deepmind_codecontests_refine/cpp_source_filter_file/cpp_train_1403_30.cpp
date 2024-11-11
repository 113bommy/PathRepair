#include <bits/stdc++.h>
using namespace std;
struct sorte {
  int ind;
  int val;
} no[200];
bool compare(sorte a, sorte b) { return a.val < b.val; }
int main() {
  int n, k;
  cin >> n >> k;
  for (int p = 0; p < n; p++) {
    cin >> no[p].val;
    no[p].ind = p + 1;
  }
  sort(no, no + n, compare);
  int s = 0;
  int i = 0;
  while (s < k) {
    s += no[i].val;
    i++;
  }
  if (s > k) i--;
  int j = 0;
  cout << i << endl;
  while (j < i) {
    cout << no[j].ind << " ";
    j++;
  }
  return 0;
}
