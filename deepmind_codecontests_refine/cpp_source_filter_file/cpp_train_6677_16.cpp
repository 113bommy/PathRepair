#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(vector<T>& V, bool spaced = true) {
  string space;
  spaced ? space = " " : space = "";
  for (int i = 0; i < V.size(); i++) {
    cout << V[i] << space;
  }
  cout << '\n';
}
template <class T>
void printendl(vector<T>& V) {
  for (int i = 0; i < V.size(); i++) {
    cout << V[i] << '\n';
  }
}
template <class T>
T gcd(T a, T b) {
  T r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class T>
T Max(T a, T b) {
  return (a < b) ? b : a;
}
template <class T>
T Min(T a, T b) {
  return (a < b) ? a : b;
}
bool isPalindrome(string str) {
  int length = str.length();
  for (int i = 0; i < (length / 2); i++)
    if (str[i] != str[length - 1 - i]) return false;
  return true;
}
void reverseStr(string& str) {
  int n = str.length();
  for (int i = 0; i < n / 2; i++) swap(str[i], str[n - i - 1]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int q;
  cin >> q;
  while (q--) {
    long long n, a, b;
    cin >> n >> a >> b;
    if (b < a) {
      cout << (n / 2) * b + (n % 2) * a << '\n';
    } else {
      cout << n * a << '\n';
    }
  }
  return 0;
}
