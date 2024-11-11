#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
bool isPalindrome(string str) {
  long long int l = 0;
  long long int h = str.length() - 1;
  while (h > l) {
    if (str[l++] != str[h--]) {
      return false;
    }
  }
  return true;
}
bool isPrime(long long int n) {
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (long long int i = 3; i <= sqrt(n); i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}
long long int countGreater(long long int arr[], long long int n,
                           long long int k) {
  long long int l = 0;
  long long int r = n - 1;
  long long int leftGreater = n;
  while (l <= r) {
    long long int m = l + (r - l) / 2;
    if (arr[m] > k) {
      leftGreater = m;
      r = m - 1;
    } else
      l = m + 1;
  }
  return (n - leftGreater);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  cout << "YES" << endl;
  bool bo[3];
  for (long long int i = 0; i < 3; i++) bo[i] = false;
  for (long long int i = 0; i < s1.length(); i++) {
    if (s1[i] == 'a')
      bo[0] = true;
    else if (s1[i] == 'b')
      bo[1] = true;
    else
      bo[2] = true;
  }
  for (long long int i = 0; i < s2.length(); i++) {
    if (s2[i] == 'a')
      bo[0] = true;
    else if (s2[i] == 'b')
      bo[1] = true;
    else
      bo[2] = true;
  }
  long long int c = 0;
  for (long long int i = 0; i < 3; i++)
    if (bo[i]) c++;
  if (c == 1) {
    for (long long int i = 0; i < n; i++) cout << "abc";
    cout << endl;
    return 0;
  }
  if (c == 2) {
    if ((s1 != "aa" && s1 != "bb" && s1 != "cc") &&
        (s2 != "aa" && s2 != "bb" && s2 != "cc")) {
      long long int key;
      for (long long int i = 0; i < 3; i++) {
        if (!bo[i]) key = i;
      }
      if (key == 0) {
        for (long long int i = 0; i < n; i++) cout << "c";
        for (long long int i = 0; i < n; i++) cout << "a";
        for (long long int i = 0; i < n; i++) cout << "b";
      }
      if (key == 1) {
        for (long long int i = 0; i < n; i++) cout << "c";
        for (long long int i = 0; i < n; i++) cout << "b";
        for (long long int i = 0; i < n; i++) cout << "a";
      }
      if (key == 2) {
        for (long long int i = 0; i < n; i++) cout << "a";
        for (long long int i = 0; i < n; i++) cout << "c";
        for (long long int i = 0; i < n; i++) cout << "b";
      }
    } else {
      bool b1 = (s1 == "aa" || s1 == "bb" || s1 == "cc");
      bool b2 = (s2 == "aa" || s2 == "bb" || s2 == "cc");
      if (b1 && b2) {
        for (long long int i = 0; i < n; i++) cout << "abc";
        return 0;
      } else if (b1) {
        map<char, long long int> mm;
        mm[s2[0]]++;
        mm[s2[1]]++;
        reverse(s2.begin(), s2.end());
        string temp = s2;
        if (mm['a'] == 0) temp.push_back('a');
        if (mm['b'] == 0) temp.push_back('b');
        if (mm['c'] == 0) temp.push_back('c');
        for (long long int i = 0; i < n; i++) cout << temp;
      } else if (b2) {
        map<char, long long int> mm;
        mm[s1[0]]++;
        mm[s1[1]]++;
        reverse(s1.begin(), s1.end());
        string temp = s1;
        if (mm['a'] == 0) temp.push_back('a');
        if (mm['b'] == 0) temp.push_back('b');
        if (mm['c'] == 0) temp.push_back('c');
        for (long long int i = 0; i < n; i++) cout << temp;
        return 0;
      }
    }
    return 0;
  }
  if (c == 3) {
    if (s1 == "aa" || s1 == "bb" || s1 == "cc") {
      reverse(s2.begin(), s2.end());
      for (long long int i = 0; i < n; i++) {
        cout << s1[0] << s2;
      }
      return 0;
    } else if (s2 == "aa" || s2 == "bb" || s2 == "cc") {
      reverse(s1.begin(), s1.end());
      for (long long int i = 0; i < n; i++) {
        cout << s1[0] << s2;
      }
      return 0;
    } else if (s1[1] == s2[0]) {
      for (long long int i = 0; i < n; i++) cout << s1[1] << s1[0] << s2[1];
    } else if (s2[1] == s1[0]) {
      for (long long int i = 0; i < n; i++) cout << s2[1] << s2[0] << s1[1];
    } else if (s1[0] == s2[0]) {
      for (long long int i = 0; i < n; i++) cout << s1[1];
      for (long long int i = 0; i < n; i++) cout << s2[1];
      for (long long int i = 0; i < n; i++) cout << s1[0];
    } else if (s1[1] == s2[1]) {
      for (long long int i = 0; i < n; i++) cout << s1[1];
      for (long long int i = 0; i < n; i++) cout << s1[0];
      for (long long int i = 0; i < n; i++) cout << s2[0];
    }
  }
  return 0;
}
