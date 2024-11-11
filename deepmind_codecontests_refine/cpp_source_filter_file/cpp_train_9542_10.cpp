#include <bits/stdc++.h>
using namespace std;
long long int nCrModp(long long int n, long long int r, long long int p) {
  long long int C[r + 1];
  memset(C, 0, sizeof(C));
  C[0] = 1;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = min(i, r); j > 0; j--) C[j] = (C[j] + C[j - 1]) % p;
  }
  return C[r];
}
long long int pos(long long int a) {
  if (a < 0) return ((-1) * a);
  return a;
}
long long int powe(long long int m, long long int b) {
  long long int i, a = 1;
  for (i = 1; i <= b; i++) a = a * m;
  return a;
}
long long int maxi(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int mini(long long int a, long long int b) {
  if (a < b) return a;
  return b;
}
long long int floorSearch(long long int arr[], long long int low,
                          long long int high, long long int x) {
  if (low > high) return -1;
  if (x >= arr[high]) return high;
  int mid = (low + high) / 2;
  if (arr[mid] == x) return mid;
  if (mid > 0 && arr[mid - 1] <= x && x < arr[mid]) return mid - 1;
  if (x < arr[mid]) return floorSearch(arr, low, mid - 1, x);
  return floorSearch(arr, mid + 1, high, x);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  char st[100005][25];
  string str;
  map<string, long long int> mp;
  long long int n, m, k, a, b, c, val[100005] = {0}, i, j;
  map<long long int, string> mp1;
  cin >> n >> m >> k;
  for (i = 0; i < n; i++) {
    cin >> str;
    mp1[i] = str;
  }
  for (i = 0; i < n; i++) {
    cin >> a;
    mp[mp1[i]] = a;
  }
  for (i = 0; i < k; i++) {
    cin >> a;
    long long int mini;
    for (j = 0; j < a; j++) {
      cin >> val[j];
      val[j]--;
    }
    mini = mp[mp1[val[0]]];
    for (j = 1; j < a; j++) {
      c = mp[mp1[val[j]]];
      if (c < mini) mini = c;
    }
    for (j = 0; j < a; j++) {
      mp[mp1[val[j]]] = mini;
    }
  }
  long long int ansr = 0;
  for (i = 0; i < m; i++) {
    cin >> str;
    ansr = ansr + mp[str];
  }
  cout << ansr;
  return 0;
}
