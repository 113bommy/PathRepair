#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v;
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int x, y, n, i, m = 0, cou = 0, a, n1, n2, j = 0, f = 0, k = 0, l,
                            ans = 0, r, b = 0, t, tt = 1e17, c = 0, arr[200005],
                            arr2[200005], h1[2000] = {0}, h2[2000] = {0},
                            div = 0, h;
  string s3, s4, s1;
  char s2[100000];
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> arr[i] >> arr2[i];
    if (arr[i] - arr2[i] >= 0)
      h1[(arr[i] - arr2[i])]++;
    else
      h1[(arr[i] - arr2[i]) + 1000]++;
    h2[(arr[i] + arr2[i])]++;
  }
  for (i = 0; i < 2000; i++) {
    if (h1[i] > 1) {
      k += (h1[i]) * (h1[i] - 1) / 2;
    }
    if (h2[i] > 1) k += (h2[i]) * (h2[i] - 1) / 2;
  }
  cout << k;
  return 0;
}
