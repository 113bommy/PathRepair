#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T GCD(T a, T b) {
  if (a < 0) return GCD(-a, b);
  if (b < 0) return GCD(a, -b);
  return (b == 0) ? a : GCD(b, a % b);
}
template <class T>
inline T LCM(T a, T b) {
  if (a < 0) return LCM(-a, b);
  if (b < 0) return LCM(a, -b);
  return a * (b / GCD(a, b));
}
template <class T>
inline bool isPrime(T n) {
  if (n < 2) return false;
  for (T i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
template <class T>
vector<T> Divisor(T num) {
  vector<T> res;
  res.clear();
  for (int i = 1; i <= num / 2; i++)
    if (num % i == 0) res.push_back(i);
  return res;
}
template <class T, class M>
inline T POWER(T x, M y) {
  T temp = 1;
  if (y == 0) return 1;
  for (int i = 1; i <= y; i++) temp *= x;
  return temp;
}
template <class T, class M>
bool Exist(T x, M element) {
  for (int i = 0; i < x.size(); i++)
    if (x[i] == element) return true;
  return false;
}
template <class T>
vector<T> Unique(vector<T> v) {
  T temp;
  vector<T> res;
  res.clear();
  for (int i = 0; i < v.size(); i++) {
    temp = v[i];
    if (Exist(res, temp) == false) res.push_back(temp);
  }
  return res;
}
template <class T>
vector<T> Parse(T temp) {
  vector<T> ans;
  ans.clear();
  T s;
  istringstream is(temp);
  while (is >> s) {
    ans.push_back(s);
  }
  return ans;
}
template <class T>
string toString(T x) {
  stringstream s;
  s << x;
  return s.str();
}
template <class T>
long long toInt(T x) {
  istringstream is(x);
  long long num;
  is >> num;
  return num;
}
template <class T>
inline void checkMin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
inline void checkMax(T &a, T b) {
  if (b > a) a = b;
}
bool isLowerCase(char c) { return (c >= 'a' && c <= 'z'); }
bool isUpperCase(char c) { return (c >= 'A' && c <= 'Z'); }
char toLowerCase(char c) { return (isUpperCase(c) ? (c + 32) : c); }
char toUpperCase(char c) { return (isLowerCase(c) ? (c - 32) : c); }
bool isLetter(char c) { return (isUpperCase(c)) || (isLowerCase(c)); }
bool isDigit(char c) { return (c >= '0' && c <= '9'); }
template <class T>
void print(T ans) {
  for (unsigned int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  cout << endl;
}
template <class T>
void print2(T ans) {
  cout << ans;
  cout << endl;
}
int doIt(string str) {
  if (str == "S") return 0;
  if (str == "M") return 1;
  if (str == "L") return 2;
  if (str == "XL") return 3;
  if (str == "XXL") return 4;
}
int main() {
  string size[] = {"S", "M", "L", "XL", "XLL"};
  vector<string> ans;
  vector<int> num(5);
  int k;
  for (int i = 0; i < 5; i++) cin >> num[i];
  cin >> k;
  vector<string> ask(k);
  for (int i = 0; i < k; i++) cin >> ask[i];
  for (int i = 0; i < ((int)(ask).size()); i++) {
    int index = doIt(ask[i]);
    int step = 1;
    if (num[index] > 0) {
      num[index]--;
      ans.push_back(size[index]);
    } else {
      while (true) {
        if (index + step < 5 && num[index + step] > 0) {
          num[index + step]--;
          ans.push_back(size[index + step]);
          break;
        } else if (index - step >= 0 && num[index - step] > 0) {
          num[index - step]--;
          ans.push_back(size[index - step]);
          break;
        }
        step++;
      }
    }
  }
  for (int i = 0; i < ((int)(ans).size()); i++) cout << ans[i] << endl;
  return 0;
}
