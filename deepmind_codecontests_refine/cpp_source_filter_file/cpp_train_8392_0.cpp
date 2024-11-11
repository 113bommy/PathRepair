#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
int main() {
  long long int i, j, k, l, m, n, t;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  string a, arr = "";
  cin >> a;
  long long int b[127], count = 0;
  for (i = 0; i < 127; i++) {
    b[i] = 0;
  }
  for (i = 0; i < n; i++) {
    b[a[i]]++;
  }
  for (i = 0; i < 127; i++) {
    if (b[i] % 2) {
      count++;
      arr += (char)i;
      b[i]--;
    }
  }
  string an = "";
  if (count == 0) {
    cout << 1 << endl;
    for (i = 0; i < 127; i++) {
      while (b[i]) {
        an += (char)i;
        b[i] -= 2;
      }
    }
    for (l = an.length() - 1; l >= 0; l--) {
      cout << an[l];
    }
    cout << an << endl;
  } else if (n % count == 0 && (n / count) % 2 == 1) {
    cout << count << endl;
    k = 0;
    for (i = 0; i < count; i++) {
      an = arr[i];
      j = 1;
      while (j < n / count) {
        while (b[k] == 0) {
          k++;
        }
        an += (char)k;
        b[k] -= 2;
        j += 2;
      }
      for (l = an.length() - 1; l >= 0; l--) {
        cout << an[l];
      }
      cout << an << " ";
    }
  } else {
    for (i = count; i < n; i++) {
      if (n % i == 0 && (n / i) % 2 == 1) {
        break;
      }
    }
    k = 0;
    for (; count < i; count++) {
      while (b[k] == 0) {
        k++;
      }
      arr += (char)k;
      b[k]--;
    }
    cout << count << endl;
    k = 0;
    for (i = 0; i < count; i++) {
      an = arr[i];
      j = 1;
      while (j < n / count) {
        while (b[k] == 0) {
          k++;
        }
        an += (char)k;
        b[k] -= 2;
        j += 2;
      }
      for (l = an.length() - 1; l > 0; l--) {
        cout << an[l];
      }
      cout << an << " ";
    }
  }
  return 0;
}
