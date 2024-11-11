#include <bits/stdc++.h>
using namespace std;
const int M = (int)(2e6 + 239);
void decitobinbitodeci() {
  string binary = bitset<8>(128).to_string();
  cout << binary << "\n";
  unsigned long decimal = bitset<8>(binary).to_ulong();
  cout << decimal << "\n";
}
int getnum(string a) {
  int i, p = 0;
  for (i = 0; i < a.size(); i++) {
    p *= 10;
    p += a[i] - '0';
  }
  return p;
}
long long getOddOccurrence(long long ar[], int ar_size) {
  long long res = 0;
  for (int i = 0; i < ar_size; i++) res = res ^ ar[i];
  return res;
}
bool areEqual(int arr1[], int arr2[], int n, int m) {
  if (n != m) return false;
  unordered_map<int, int> mp;
  for (int i = 0; i < n; i++) mp[arr1[i]]++;
  for (int i = 0; i < n; i++) {
    if (mp.find(arr2[i]) == mp.end()) return false;
    if (mp[arr2[i]] == 0) return false;
    mp[arr2[i]]--;
  }
  return true;
}
long long binarySearch(long long arr[], long long l, long long r, long long x) {
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (arr[m] == x) return m;
    if (arr[m] < x)
      l = m + 1;
    else
      r = m - 1;
  }
  return -1;
}
long long power(long long x, unsigned long long int y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long countOddSum(long long a[], long long n) {
  long long odd = 0, c_odd = 0, result = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] & 1) {
      odd = !odd;
    }
    if (odd) {
      c_odd++;
    }
  }
  for (int i = 0; i < n; i++) {
    result += c_odd;
    if (a[i] & 1) {
      c_odd = (n - i - c_odd);
    }
  }
  return result;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long a = 0, b = 0, c, d;
  char x[8][8];
  map<char, long long> m;
  m['Q'] = 9;
  m['R'] = 5;
  m['B'] = 3;
  m['K'] = 3;
  m['P'] = 1;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> x[i][j];
      if (x[i][j] >= 'A' && x[i][j] <= 'Z') {
        a += m[x[i][j]];
      } else {
        x[i][j] = toupper(x[i][j]);
        b += m[x[i][j]];
      }
    }
  }
  if (a > b) {
    cout << "White" << endl;
  } else if (a < b) {
    cout << "Black" << endl;
  } else {
    cout << "Draw" << endl;
  }
}
