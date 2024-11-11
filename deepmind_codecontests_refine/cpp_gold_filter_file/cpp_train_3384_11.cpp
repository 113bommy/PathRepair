#include <bits/stdc++.h>
using namespace std;
int n, arr[500005], am[500005];
bool arrANS[500005];
int main() {
  scanf("%d", &n);
  for (int i = (0); i < (n); i++) scanf("%d", &arr[i]);
  memset(arrANS, false, sizeof arrANS);
  for (int i = (0); i < (n); i++) {
    if (i != 0 && i != n - 1) {
      if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1]) {
      } else
        arrANS[i] = true;
    } else
      arrANS[i] = true;
  }
  int ans = 0;
  while (true) {
    vector<pair<int, int> > vektor;
    for (int i = (0); i < (n); i++) {
      if (!arrANS[i]) {
        int first = i;
        while (!arrANS[i + 1]) i++;
        int second = i;
        vektor.push_back(make_pair((first), (second)));
      }
    }
    if (vektor.size() == 0) break;
    int length = vektor.size();
    int maxi = 0;
    for (int i = (0); i < (length); i++) {
      int temp1 = vektor[i].first;
      int temp2 = vektor[i].second;
      if (arr[temp1] == arr[temp2]) {
        int temp = 1 - arr[temp1];
        for (int j = (temp1); j < (temp2 + 1); j++) {
          arr[j] = temp;
          arrANS[j] = true;
        }
      } else {
        int temp = arr[temp2];
        for (int j = (temp1); j < ((temp1 + temp2 + 1) / 2); j++) {
          arr[j] = temp;
          arrANS[j] = true;
        }
        for (int j = ((temp1 + temp2 + 1) / 2); j < (temp2 + 1); j++) {
          arr[j] = 1 - temp;
          arrANS[j] = true;
        }
      }
      maxi = max(maxi, (temp2 - temp1 + 2) / 2);
    }
    ans += maxi;
  }
  printf("%d\n", ans);
  for (int i = (0); i < (n - 1); i++) printf("%d ", arr[i]);
  printf("%d\n", arr[n - 1]);
  return 0;
}
