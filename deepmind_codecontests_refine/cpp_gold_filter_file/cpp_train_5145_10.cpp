#include <bits/stdc++.h>
using namespace std;
int BS(int num, vector<int>& a) {
  int lo = 0;
  int hi = a.size();
  while (lo != hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] <= num)
      lo = mid + 1;
    else
      hi = mid;
  }
  return lo;
}
int main() {
  int n;
  cin >> n;
  vector<int> Kango(n);
  for (int i = 0; i < n; i++) scanf("%d", &Kango[i]);
  sort(Kango.begin(), Kango.end());
  int hid = 0;
  int j = Kango.size() / 2;
  for (int i = 0; i < Kango.size() / 2; i++) {
    for (; j < Kango.size(); j++) {
      if (Kango[i] * 2 <= Kango[j]) {
        hid++;
        j++;
        break;
      }
    }
  }
  cout << Kango.size() - hid;
  return 0;
}
