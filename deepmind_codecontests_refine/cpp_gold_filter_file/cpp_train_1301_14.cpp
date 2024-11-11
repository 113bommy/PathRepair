#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, rating[100000], rating1[100000], hash[10], k, i, points = 0,
                                                                    poss;
  cin >> n >> k;
  for (i = 0; i < 10; i++) {
    hash[i] = 0;
  }
  for (i = 0; i < n; i++) {
    cin >> rating[i];
    hash[rating[i] % 10] += 1;
    poss += rating[i];
    points += rating[i] / 10;
  }
  if (k >= n * 100 - poss)
    cout << 10 * n;
  else {
    for (i = 1; i < 10; i++) hash[i] += hash[i - 1];
    for (i = n - 1; i >= 0; i--) {
      rating1[hash[rating[i] % 10] - 1] = rating[i];
      hash[rating[i] % 10]--;
    }
    for (i = n - 1; k > 0 && i >= 0; i--) {
      if (k >= 10 - rating1[i] % 10) {
        k -= 10 - rating1[i] % 10;
        points++;
        rating1[i] += 10 - rating1[i] % 10;
      } else
        break;
    }
    i = n - 1;
    while (k > 10) {
      if (rating1[i] >= 100) {
        i--;
        continue;
      }
      if (k >= 100 - rating1[i]) {
        k -= 100 - rating1[i];
        points += (100 - rating1[i]) / 10;
      } else {
        points += k / 10;
        break;
      }
      i--;
    }
    cout << points;
  }
  return 0;
}
