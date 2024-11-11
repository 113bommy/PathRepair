#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long int* arr = (long long int*)malloc(n * sizeof(long long int));
  std::vector<int> v;
  for (int i1 = 0; i1 < n; i1++) {
    cin >> arr[i1];
    if (arr[i1] == 0) v.push_back(i1);
  }
  long long int* a = (long long int*)malloc(n * sizeof(long long int));
  for (int i = 0; i < n; i++) {
    if (arr[i] == 0)
      a[i] = 0;
    else {
      long long int dif = INT_MAX;
      int l = 0, r = v.size();
      while (l <= r) {
        int m = l + (r - l) / 2;
        long long int dif1 = (v[m] - i);
        if (abs(dif1) < dif)
          dif = abs(dif1);
        else if (dif1 < 0)
          l = m + 1;
        else
          r = m - 1;
      }
      a[i] = dif;
    }
  }
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << endl;
  return 0;
}
