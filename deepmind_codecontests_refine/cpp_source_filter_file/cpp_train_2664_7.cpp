#include <bits/stdc++.h>
using namespace std;
void out(int a) { cerr << a; }
void out(long long a) { cerr << a; }
void out(char a) { cerr << a; }
void out(string a) { cerr << a; }
void out(bool a) { cerr << a; }
void out(double a) { cerr << a; }
template <class T, class V>
void out(pair<T, V> p);
template <class T>
void out(vector<T> v);
template <class T>
void out(set<T> v);
template <class T, class V>
void out(map<T, V> v);
template <class T>
void out(multiset<T> v);
template <class T, class V>
void out(pair<T, V> p) {
  cerr << "{";
  out(p.first);
  cerr << ",";
  out(p.second);
  cerr << "}";
}
template <class T>
void out(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    out(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void out(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    out(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void out(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    out(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void out(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    out(i);
    cerr << " ";
  }
  cerr << "]";
}
vector<long long> sieve(long long n) {
  vector<bool> prime(n + 1, true);
  for (long long p = 2; p * p <= n; p++)
    if (prime[p] == true)
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
  vector<long long> v;
  for (long long p = 2; p <= n; p++) {
    if (prime[p]) v.push_back(p);
  }
  return v;
}
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
void solve() {
  int n;
  cin >> n;
  map<int, char> v;
  v[0] = 'R';
  v[1] = 'O';
  v[2] = 'Y';
  v[3] = 'G';
  v[4] = 'B';
  v[5] = 'I';
  v[6] = 'V';
  int flag = n % 7, q = n / 7, done = 0;
  if (flag == 1 || flag == 2 || flag == 3) {
    for (int i = 0; i < n - flag; i++) {
      if (i / 7 == q - 1 && done == 0 && i % 7 == 4) {
        for (int j = 0; j < flag; j++) {
          cout << v[j];
        }
        done = 1;
      }
      cout << v[i];
    }
  } else {
    for (int i = 0; i < n; i++) {
      cout << v[i % 7];
    }
  }
}
int main() { solve(); }
