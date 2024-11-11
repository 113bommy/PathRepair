#include <bits/stdc++.h>
using namespace std;
bool isprime(int n) {
  if (n == 1) return false;
  if (n == 2) return true;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
void answer(int f) {
  if (f) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  cout << endl;
}
long long int countSetBits(long long int n) {
  long long int count = 0;
  while (n) {
    count += n & 1;
    n >>= 1;
  }
  return count;
}
long long int factorial(long long int n) {
  n = n % 1000000007;
  return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}
long long int FastExp(long long int a, long long int b) {
  long long int ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % 1000000007;
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return (ans % 1000000007);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int test = 1;
  cin >> test;
  while (test--) {
    string str;
    cin >> str;
    int n = str.length(), i;
    char a[52];
    for (i = 0; i < 52; i++) {
      a[i] = '1';
    }
    int j = 27;
    int f = 1;
    i = 0;
    set<char> s;
    while (i < n) {
      if (s.find(str[i]) == s.end()) {
        if (a[j + 1] == '1') {
          j++;
          a[j] = str[i];
        } else if (a[j - 1] == '1') {
          j--;
          a[j] = str[i];
        } else {
          f = 0;
          break;
        }
        s.insert(str[i]);
      } else {
        if (a[j - 1] == str[i])
          j--;
        else if (a[j + 1] == str[i])
          j++;
        else {
          f = 0;
          break;
        }
      }
      i++;
    }
    answer(f);
    if (!f) continue;
    for (i = 0; i < 52; i++) {
      if (a[i] == '1') continue;
      cout << a[i];
    }
    for (char f = 'a'; f <= 'z'; f++) {
      if (s.find(f) == s.end()) cout << f;
    }
    cout << endl;
  }
  return 0;
}
