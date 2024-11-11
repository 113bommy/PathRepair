#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  return (b != 0 ? gcd<T>(b, a % b) : a);
}
template <class T>
T lcm(T a, T b) {
  return (a / gcd<T>(a, b) * b);
}
double tick() {
  static clock_t oldt, newt = clock();
  double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC;
  oldt = newt;
  return diff;
}
float roundoff(float val, float p) {
  return floor(val * pow(10.0, p) + 0.5) / pow(10.0, p);
}
long long int power(long long int a, long long int b, long long int mod) {
  long long int x = 1, y = a;
  while (b > 0) {
    if (b & 1) {
      x = (x * y) % mod;
    }
    y = (y * y) % mod;
    b /= 2;
  }
  return x;
}
const int INF = 0x3f3f3f3f;
const float pi = 3.14159265;
int main(void) {
  ios_base::sync_with_stdio(true);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, k, l;
  scanf("%lld %lld %lld", &n, &k, &l);
  vector<long long int> arr;
  for (int i = 0; i < n * k; i++) {
    long long int temp;
    scanf("%lld", &temp);
    arr.push_back(temp);
  }
  sort(arr.begin(), arr.end());
  vector<long long int> arr2;
  arr2.push_back(arr[0]);
  int idx = 0;
  for (int i = 1; i < n * k; i++) {
    if (arr[i] - arr[0] <= l) {
      arr2.push_back(arr[i]);
      idx = i;
    } else {
      break;
    }
  }
  cerr << "idx"
       << ": " << idx << '\n';
  long long int m = n * k;
  if (k == 1) {
    if (arr[m - 1] - arr[0] <= l) {
      cout << accumulate(arr.begin(), arr.end(), 0LL);
      return 0;
    } else {
      cout << 0;
      return 0;
    }
  }
  if (n == 1) {
    cout << arr[0];
    return 0;
  }
  long long int ans = 0;
  if (arr2.size() < n) {
    cout << 0;
    return 0;
  } else {
    long long int ngrtr = m - 1 - idx;
    long long int r = ngrtr / (k - 1);
    long long int rr = r;
    cerr << "ngrtr"
         << ": " << ngrtr << " | "
         << "r"
         << ": " << r << '\n';
    long long int rem = ngrtr % (k - 1);
    int sze = arr2.size();
    idx = sze - 1;
    for (int i = sze - 1; rr > 0; i--) {
      ans += arr2[i];
      idx = i;
      rr--;
    }
    int left = n - r;
    cerr << "idx"
         << ":" << idx << " | "
         << "ans"
         << ": " << ans << " | "
         << "left"
         << ": " << left << '\n';
    if (left > 0) {
      int go = idx + rem - k;
      cerr << "go"
           << ": " << go << '\n';
      ans += arr2[go];
      left--;
      cerr << "left"
           << ": " << left << '\n';
      if (left > 0) {
        int cnt = 0;
        for (int i = go - 1; i >= 0; i--) {
          cnt++;
          if (cnt == k) {
            ans += arr2[i];
            cnt = 0;
          }
        }
      }
    }
    cout << ans;
  }
  return 0;
}
