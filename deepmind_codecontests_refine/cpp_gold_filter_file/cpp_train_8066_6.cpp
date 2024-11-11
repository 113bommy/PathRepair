#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, j, x, a;
  std::ios_base::sync_with_stdio(false);
  cin >> n;
  long long app[n];
  long long pos[n];
  for (i = 0; i < n; i++) {
    cin >> x >> a;
    pos[i] = x;
    app[i] = a;
  }
  long long temp;
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (pos[i] > pos[j]) {
        temp = pos[i];
        pos[i] = pos[j];
        pos[j] = temp;
        temp = app[i];
        app[i] = app[j];
        app[j] = temp;
      }
    }
  }
  long long countn = 0;
  long long countp = 0;
  for (i = 0; i < n; i++) {
    if (pos[i] < 0) {
      countn++;
    } else {
      countp++;
    }
  }
  long long indp = n;
  for (i = 0; i < n; i++) {
    if (pos[i] > 0) {
      indp = i;
      break;
    }
  }
  if (countn > countp) {
    long long ans = 0;
    for (i = 0; i < n; i++) {
      if (pos[i] > 0) {
        ans += app[i];
      }
    }
    long long count = 0;
    for (i = indp - 1; i >= 0; i--) {
      ans += app[i];
      count++;
      if (count == countp + 1) {
        break;
      }
    }
    cout << ans << endl;
  }
  if (countn <= countp) {
    long long ans = 0;
    for (i = 0; i < n; i++) {
      if (pos[i] > 0) {
        break;
      }
      ans += app[i];
    }
    long long count = 0;
    for (i = indp; i < n; i++) {
      ans += app[i];
      count++;
      if (count == countn + 1) {
        break;
      }
    }
    cout << ans << endl;
  }
}
