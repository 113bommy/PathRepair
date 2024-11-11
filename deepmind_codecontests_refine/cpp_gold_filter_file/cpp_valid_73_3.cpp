#include <bits/stdc++.h>
using namespace std;
long long dx[] = {0, -1, 0, 1};
long long dy[] = {1, 0, -1, 0};
const long long mod = 1e9 + 7;
inline long long add(long long a, long long b) {
  return ((a % mod) + (b % mod) + mod) % mod;
}
inline long long mul(long long a, long long b) {
  return ((a % mod) * (b % mod) + mod) % mod;
}
void pause(long long id) {
  cout << "Waiting " << id << endl;
  cin >> id;
}
const int mxn = 1e5 + 10;
void init() { return; }
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  if (!true) {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  }
  init();
  long long i, j;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long brr[n + 1], arr[n + 1];
    for (i = 1; i <= n; i++) {
      cin >> arr[i];
      brr[i] = arr[i];
    }
    sort(brr + 1, brr + n + 1);
    long long cnt = 0;
    bool flag = false;
    bool temp = true;
    for (i = 1; i <= n; i++) {
      temp = temp && arr[i] == brr[i];
    }
    flag = flag || temp;
    i = 1;
    long long ok = 30;
    while (!flag) {
      cnt++;
      if (i % 2 == 1) {
        for (j = 1; j <= n - 2; j += 2) {
          if (arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
          }
        }
      } else {
        for (j = 2; j <= n - 1; j += 2) {
          if (arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
          }
        }
      }
      bool temp = true;
      for (j = 1; j <= n; j++) {
        temp = temp && arr[j] == brr[j];
      }
      flag = flag || temp;
      i++;
    }
    cout << cnt << endl;
  }
  return 0;
}
