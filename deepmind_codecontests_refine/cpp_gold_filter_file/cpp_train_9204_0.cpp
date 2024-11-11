#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, temp;
long long int cei, jiro;
int main() {
  cin >> n;
  vector<int> a;
  for (i = 0; i < n; i++) {
    cin >> k;
    if (k % 2) {
      for (j = 1; j <= k; j++) {
        cin >> temp;
        if ((k + 1) / 2 > j)
          cei += temp;
        else if ((k + 1) / 2 < j)
          jiro += temp;
        else
          a.push_back(temp);
      }
    } else {
      for (j = 1; j <= k; j++) {
        cin >> temp;
        if ((k + 1) / 2 >= j)
          cei += temp;
        else if ((k + 1) / 2 < j)
          jiro += temp;
      }
    }
  }
  sort(a.begin(), a.end());
  j = 0;
  for (i = a.size() - 1; i >= 0; i--) {
    if (j % 2 == 0)
      cei += a[i];
    else
      jiro += a[i];
    j++;
  }
  cout << cei << " " << jiro << "\n";
}
