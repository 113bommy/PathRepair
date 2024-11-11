#include <bits/stdc++.h>
using namespace std;
int minimum(int x, int y) { return (x < y ? x : y); }
template <typename type>
struct speciealAlgorithm {
  bool operator()(const type &x, const type &y) const { return x > y; }
};
bool prime(int x) {
  if (x == 2) return false;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}
bool flusher(int x) {
  string s;
  cout << x << endl;
  fflush(stdout);
  cin >> s;
  return s == "yes";
}
long long int magic(string s) {
  long long int sum = 0;
  for (int i = 0; i < s.size(); i++) {
    sum += s[i] - '0';
  }
  return sum;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  string s;
  cin >> s;
  int operation = 0;
  int len = s.size();
  int sum = 0;
  for (int i = 0; i < len; i++) {
    sum += s[i] - '0';
  }
  if (len >= 2) {
    operation++;
  }
  while (sum >= 10) {
    operation++;
    int temp = 0;
    sum *= 10;
    while (sum /= 10) {
      temp += sum % 10;
    }
    sum = temp;
  }
  cout << operation << endl;
  return 0;
}
