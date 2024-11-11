#include <bits/stdc++.h>
using namespace std;
void READ(vector<long long> &v, long long n) {
  long long a;
  for (long long i = 0; i < n; i = i + 1) {
    cin >> a;
    v.push_back(a);
  }
}
void PRINT(vector<long long> &v, long long a = 0) {
  for (long long i = a; i < v.size(); i = i + 1) {
    cout << v[i] << " ";
  }
  cout << "\n";
}
double logy(long long n, long long b) {
  if (b == 0) {
    return (-1);
  }
  if (n == 1) {
    return (0);
  }
  return ((double)log10(n) / log10(b));
}
long long power(long long k, long long n, long long m = 1000000007) {
  long long res = 1;
  while (n) {
    if (n % 2 != 0) {
      res = (res * k) % m;
    }
    k = (k * k) % m;
    n = n / 2;
  }
  return (res);
}
double power(double k, long long n) {
  double res = 1;
  while (n) {
    if (n % 2 != 0) {
      res = (res * k);
    }
    k = (k * k);
    n = n / 2;
  }
  return (res);
}
double distance(pair<long long, long long> a, pair<long long, long long> b) {
  return ((double)(sqrt((a.first - b.first) * (a.first - b.first) +
                        (a.second - b.second) * (a.second - b.second))));
}
const long long dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const long long dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<pair<long long, long long> > dr;
long long n, m, k, h;
bool ok = false;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  std::cout.unsetf(std::ios::floatfield);
  std::cout.precision((long long)10);
  long long a, b, c, d, i, j, t, x, y, z;
  double p, q, r, u, w;
  string str, st, str1, str2, str3, str4;
  cin >> t;
  while (t--) {
    cin >> h >> n;
    vector<long long> v;
    map<long long, long long> hai;
    for (i = 0; i < n; i++) {
      cin >> a;
      v.push_back(a);
      hai[a] = 1;
    }
    x = 0;
    for (j = 0; j < n;) {
      i = v[j];
      if (i <= 2) {
        break;
      }
      if (!hai[i - 1]) {
        if (i - 1 <= 2) {
          break;
        }
        j++;
        while (j < n) {
          if (hai[v[j]] && hai[v[j] - 1]) {
            j++;
            break;
          }
          if (v[j] <= 1) {
            break;
          }
          x++;
          j++;
        }
        if (j < n && v[j] <= 1) {
          break;
        }
        continue;
      }
      if (hai[i - 1] && hai[i - 2]) {
        j += 2;
        continue;
      }
      if (hai[i - 1]) {
        x++;
        if (i - 2 <= 2) {
          break;
        }
        j += 2;
        while (j < n) {
          if (hai[v[j]] && hai[v[j] - 1]) {
            j++;
            break;
          }
          if (v[j] <= 1) {
            break;
          }
          x++;
          j++;
        }
        if (j < n && v[j] <= 1) {
          break;
        }
      }
    }
    cout << x << "\n";
  }
}
