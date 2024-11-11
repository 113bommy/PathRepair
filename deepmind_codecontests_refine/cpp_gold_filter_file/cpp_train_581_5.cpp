#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return a * b / gcd(a, b);
}
long long int max(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int min(long long int a, long long int b) {
  if (a < b) return a;
  return b;
}
long long int bins(long long int arr[], long long int l, long long int r,
                   long long int x) {
  if (r >= l) {
    long long int mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return bins(arr, l, mid - 1, x);
    return bins(arr, mid + 1, r, x);
  }
  return -1;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string s;
  cin >> s;
  long long int a[6], b[6];
  for (int i = 0; i < 6; i++) {
    a[i] = s[i] - '0';
    b[i] = 9 - a[i];
  }
  long long int s1 = a[0] + a[1] + a[2];
  long long int s2 = a[3] + a[4] + a[5];
  long long int k;
  long long int t;
  long long int c = 0;
  long long int ans;
  if (s1 == s2)
    ans = 0;
  else if (s1 > s2) {
    k = s1 - s2;
    t = k;
    sort(b + 3, b + 6);
    if (t > 0) {
      c++;
      t -= b[5];
    }
    if (t > 0) {
      c++;
      t -= b[4];
    }
    if (t > 0) {
      c++;
      t -= b[3];
    }
    ans = c;
    t = k;
    c = 0;
    sort(a, a + 3);
    if (t > 0) {
      c++;
      t -= a[2];
    }
    if (t > 0) {
      c++;
      t -= a[1];
    }
    if (t > 0) {
      c++;
      t -= a[0];
    }
    ans = min(c, ans);
    t = k;
    c = 0;
    if (t > 0) {
      c++;
      t -= a[2];
    }
    if (t > 0) {
      c++;
      t -= b[5];
    }
    if (t <= 0) ans = min(c, ans);
  } else {
    k = s2 - s1;
    t = k;
    sort(a + 3, a + 6);
    if (t > 0) {
      c++;
      t -= a[5];
    }
    if (t > 0) {
      c++;
      t -= a[4];
    }
    if (t > 0) {
      c++;
      t -= a[3];
    }
    ans = c;
    t = k;
    c = 0;
    sort(b, b + 3);
    if (t > 0) {
      c++;
      t -= b[2];
    }
    if (t > 0) {
      c++;
      t -= b[1];
    }
    if (t > 0) {
      c++;
      t -= b[0];
    }
    ans = min(c, ans);
    t = k;
    c = 0;
    if (t > 0) {
      c++;
      t -= b[2];
    }
    if (t > 0) {
      c++;
      t -= a[5];
    }
    if (t <= 0) ans = min(c, ans);
  }
  cout << ans;
  return 0;
}
