#include <bits/stdc++.h>
using namespace std;
vector<bool> prime(1e7 + 5, true);
void SieveOfEratosthenes(long long int n) {
  prime[0] = false;
  prime[1] = false;
  for (long long unsigned int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long unsigned int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
long long unsigned int countDivisors(long long unsigned int n) {
  long long unsigned int cnt = 0;
  for (long long unsigned int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        ++cnt;
      else
        cnt += 2;
    }
  }
  return cnt;
}
int Search(string pat, string txt) {
  int n = txt.size();
  int m = pat.size();
  for (int i = 0; i <= n - m; i++) {
    int j;
    for (j = 0; j < m; j++) {
      if (txt[i + j] != pat[j]) {
        break;
      }
    }
    if (j == m) {
      return i;
    }
  }
  return -1;
}
int findFirst(const std::vector<long long int> &array, int key, int low,
              int high) {
  int ans = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (key == array[mid]) {
      ans = mid;
      high = mid - 1;
    } else if (key > array[mid])
      low = mid + 1;
    else
      high = mid - 1;
  }
  return ans;
}
int findLast(const std::vector<long long int> &array, int key, int low,
             int high) {
  int ans = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (key == array[mid]) {
      ans = mid;
      low = mid + 1;
    } else if (key > array[mid])
      low = mid + 1;
    else
      high = mid - 1;
  }
  return ans;
}
int d, x, y;
void extendedEuclid(int a, int b) {
  if (b == 0) {
    d = 1;
    x = 1;
    y = 0;
  } else {
    extendedEuclid(b, a % b);
    int temp = x;
    x = y;
    y = temp - (a / b) * y;
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  t = 1;
  SieveOfEratosthenes(1e7 + 5);
  for (int tc = 0; tc < t; tc++) {
    int n;
    cin >> n;
    int cnt = n;
    for (int x = 2; x <= 1e7 + 5 && cnt > 0; x++) {
      if (prime[x]) {
        cout << x << " ";
        cnt--;
      }
    }
    cout << endl;
  }
  return 0;
}
