#include <bits/stdc++.h>
using namespace std;
char al[26]{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
            'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
template <typename KeyType, typename ValueType>
pair<KeyType, ValueType> get_max(const map<KeyType, ValueType> &x) {
  return *max_element(
      x.begin(), x.end(),
      [](const pair<KeyType, ValueType> &p1,
         const pair<KeyType, ValueType> &p2) { return p1.second < p2.second; });
}
long long gcd(long long a, long long b) {
  while (b != 0) {
    long long t = b;
    b = a % b;
    a = t;
  }
  return a;
}
int lstr(string s, string sub) { return s.find(sub); }
int lstr(string s, string sub, int l) { return s.find(sub, l); }
long long findlcm(int arr[], int n) {
  long long ans = arr[0];
  for (int i = 1; i < n; i++) ans = (((arr[i] * ans)) / (gcd(arr[i], ans)));
  return ans;
}
bool primes[80000000];
void pri(int n) {
  for (int i = 0; i < n + 1; i++) {
    primes[i] = 1;
  }
  for (int i = 2; i < n + 1; i++) {
    if (primes[i]) {
      for (int j = i + i; j < n + 1; j += i) {
        primes[j] = 0;
      }
    }
  }
}
int main() {
  int ans = 0;
  for (int i = 0; i < 8; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      switch (s[j]) {
        case 'q':
          ans -= 9;
          break;
        case 'Q':
          ans += 9;
          break;
        case 'r':
          ans -= 5;
          break;
        case 'R':
          ans += 5;
          break;
        case 'b':
          ans -= 3;
          break;
        case 'n':
          ans -= 3;
          break;
        case 'N':
          ans += 3;
          break;
        case 'B':
          ans += 3;
          break;
        case 'p':
          ans -= 1;
          break;
        case 'P':
          ans += 1;
          break;
      }
    }
  }
  if (ans > 0) {
    cout << "White";
  } else if (ans == 0) {
    cout << "Draw";
  } else {
    cout << "Black";
  }
}
