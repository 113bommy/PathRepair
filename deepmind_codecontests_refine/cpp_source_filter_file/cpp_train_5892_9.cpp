#include <bits/stdc++.h>
using namespace std;
int e[100005];
int o[100005];
int arr[100005];
int main() {
  int n;
  cin >> n;
  int ke = 0, ko = 0;
  for (int i = 0; i < n; ++i) cin >> arr[i];
  for (int i = 0; i < n; ++i) {
    if (arr[i] < 0) {
      if ((-arr[i]) % 2 == 1)
        o[ko++] = arr[i];
      else
        e[ke++] = arr[i];
    } else {
      if (arr[i] % 2 == 1)
        o[ko++] = arr[i];
      else
        e[ke++] = arr[i];
    }
  }
  sort(e, e + ke);
  sort(o, o + ko);
  long long int sum = o[ko - 1];
  for (int i = ke - 1; i > -1; --i) {
    if (e[i] > 0)
      sum += e[i];
    else
      break;
  }
  for (int i = ko - 2; i > -1; i -= 2) {
    if (o[i] + o[i - 1] > 0) {
      sum += o[i] + o[i - 1];
    } else
      break;
  }
  cout << sum << endl;
}
