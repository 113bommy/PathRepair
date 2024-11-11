#include <bits/stdc++.h>
using namespace std;
bool isPrime(int x) {
  if (x == 1) {
    return false;
  }
  if (x == 2 || x == 3) {
    return true;
  }
  if (x % 2 == 0 || x % 3 == 0) {
    return false;
  }
  for (int i = 5; i * i <= x; i += 6) {
    if (x % i == 0 || x % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}
long long gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(int a, int b) { return (a / gcd(a, b)) * b; }
long long int power(long long int a, long long int n, long long int p) {
  long long int res = 1;
  while (n) {
    if (n % 2) {
      res = ((res % p) * (a % p)) % p;
    }
    a = ((a % p) * (a % p)) % p;
    n /= 2;
  }
  return res;
}
void sieve() {
  int arr[1000001];
  int maxN = 1000000;
  for (int i = 1; i <= maxN; i++) {
    arr[i] = -1;
  }
  for (int i = 2; i <= maxN; i++) {
    if (arr[i] == -1) {
      for (int j = i; j <= maxN; j += i) {
        if (arr[j] == -1) {
          arr[j] = i;
        }
      }
    }
  }
  int n = 100;
  cout << arr[n];
  n /= arr[n];
  while (n > 1) {
    cout << " x " << arr[n];
    n /= arr[n];
  }
}
long long int ncr(long long int n, long long int r) {
  long long int res = 1;
  if (r > n - r) {
    r = n - r;
  }
  for (long long int i = 0; i < r; i++) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
void show(vector<long long int> ans) {
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
void factorize(vector<pair<long long int, long long int>> &v,
               long long int num) {
  for (long long int i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      int cnt = 0;
      while (num % i == 0) {
        cnt++;
        num /= i;
      }
      v.push_back({i, cnt});
    }
  }
  if (num > 1) {
    v.push_back({num, 1});
  }
}
int decode() {
  long long int r, g, b, w;
  cin >> r >> g >> b >> w;
  int odd = 0;
  if (r % 2 != 0) {
    odd++;
  }
  if (g % 2 != 0) {
    odd++;
  }
  if (b % 2 != 0) {
    odd++;
  }
  if (w % 2 != 0) {
    odd++;
  }
  if (odd <= 1) {
    cout << "Yes"
         << "\n";
  } else {
    w += 3;
    r--;
    g--;
    b--;
    if (r < 0 || g < 0 || b < 0) {
      cout << "No"
           << "\n";
    } else {
      odd = 0;
      if (r % 2 != 0) {
        odd++;
      }
      if (g % 2 != 0) {
        odd++;
      }
      if (b % 2 != 0) {
        odd++;
      }
      if (w % 2 != 0) {
        odd++;
      }
      if (odd <= 1) {
        cout << "Yes"
             << "\n";
      } else {
        cout << "No"
             << "\n";
      }
    }
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    decode();
  }
  return 0;
}
