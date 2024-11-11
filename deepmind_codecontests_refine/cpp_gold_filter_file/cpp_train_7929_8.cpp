#include <bits/stdc++.h>
using namespace std;
long mod = pow(10, 9) + 7;
int countdivisors(int n) {
  long long count = 0;
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i) {
        count++;
      } else {
        count = count + 2;
      }
    }
  }
  return count;
}
void remove(std::vector<int> &v) {
  auto end = v.end();
  for (auto it = v.begin(); it != end; ++it) {
    end = std::remove(it + 1, end, *it);
  }
  v.erase(end, v.end());
}
bool isPerfectSquare(int x) {
  int s = sqrt(x);
  return (s * s == x);
}
bool isFibonacci(int n) {
  return isPerfectSquare(5 * n * n + 4) || isPerfectSquare(5 * n * n - 4);
}
int digSum(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n = n / 10;
  }
  return sum;
}
long long exponentMod(long long A, long long B, long long C) {
  if (A == 0) return 0;
  if (B == 0) return 1;
  long long y;
  if (B % 2 == 0) {
    y = exponentMod(A, B / 2, C);
    y = (y * y) % C;
  } else {
    y = A % C;
    y = (y * exponentMod(A, B - 1, C) % C) % C;
  }
  return (long long)((y + C) % C);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> x;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    x.push_back(a[i]);
  }
  int m;
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    x.push_back(b[i]);
  }
  int t = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      vector<int>::iterator it;
      it = find(x.begin(), x.end(), a[i] + b[j]);
      if (it == x.end()) {
        cout << a[i] << " " << b[j];
        t++;
        break;
      }
    }
    if (t != 0) {
      break;
    }
  }
  return 0;
}
