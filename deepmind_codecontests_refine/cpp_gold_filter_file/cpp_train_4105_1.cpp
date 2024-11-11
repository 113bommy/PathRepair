#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  int* prices = new int[k];
  for (int i = 0; i < k; i++) cin >> prices[i];
  int max = 0, maxCount, premax = 0;
  for (int i = 0; i < k; i++)
    if (max < prices[i]) {
      max = prices[i];
      maxCount = i;
    }
  for (int i = 0; i < k; i++)
    if (premax < prices[i] && prices[i] != max) premax = prices[i];
  cout << maxCount + 1 << " " << premax << endl;
}
