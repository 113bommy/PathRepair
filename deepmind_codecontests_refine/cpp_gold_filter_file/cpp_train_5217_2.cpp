#include <bits/stdc++.h>
using namespace std;
template <class T>
string change(T b) {
  string s;
  string Result;
  ostringstream convert;
  convert << b;
  Result = convert.str();
  return Result;
}
template <class T, class N>
T change1(N b, T s) {
  stringstream x1;
  x1 << b;
  x1 >> s;
  return s;
}
long long index1(string s) {
  for (long long i = 0; i < s.length(); i++) {
    if (s[i] == ' ') return i;
  }
}
string ahmed(string s) {
  string s1;
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == ' ') break;
    s1 += s[i];
  }
  return s1;
}
string osama(long long n, string s) {
  string s1;
  for (long long i = n + 1; i < s.length(); i++) {
    s1 += s[i];
  }
  return s1;
}
template <class T>
long long repeat(vector<T> v, T x) {
  long long count = 0;
  for (long long i = 0; i < v.size(); i++) {
    if (x == v[i]) count++;
  }
  return count;
}
long long search2(string s, string arr[]) {
  for (long long i = 0; i < 10; i++) {
    if (arr[i] == s) {
      return i;
    }
  }
  return -1;
}
bool minimum(vector<long long> v, long long m) {
  long long min = v[0];
  for (long long i = 1; i < v.size(); i++) {
    if (v[i] < min) min = v[i];
  }
  if (m == min) return 1;
  return 0;
}
long long compare(string s, string s1) {
  long long count = 0;
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] != s1[i]) count++;
  }
  return count;
}
bool isequal(string s, string s1) {
  for (long long i = 0; i < s.size(); i++) {
    for (long long j = 0; j < s1.size(); j++) {
      if (s[i] == s1[j]) return 1;
    }
  }
  return 0;
}
long long avg(vector<long long> v1) {
  long long sum = 0;
  for (long long i = 0; i < v1.size(); i++) {
    sum += v1[i];
  }
  return sum / (v1.size());
}
bool isqeal(vector<string> v, string s) {
  for (long long i = 0; i < v.size(); i++) {
    if (s == v[i]) return true;
  }
  return false;
}
long long search1(char c, string s) {
  for (long long i = 0; i < s.size(); i++) {
    if (c == s[i]) {
      return i;
    }
  }
  return -1;
}
bool seen(string s1, string s2) {
  std::sort(s1.begin(), s1.end());
  s1.erase(std::unique(s1.begin(), s1.end()), s1.end());
  std::sort(s2.begin(), s2.end());
  s2.erase(std::unique(s2.begin(), s2.end()), s2.end());
  if (s1.size() == s2.size()) return 1;
}
class Mailbox {
 public:
};
long long gcd(long long number1, long long number2) {
  while (number1 != number2) {
    if (number1 > number2)
      number1 = number1 - number2;
    else if (number2 > number1)
      number2 = number2 - number1;
  }
  return number1;
}
void selectionSort(vector<long long>& numbers, vector<long long>& numbers1) {
  long long i, j;
  long long min, temp, temp2;
  for (i = 0; i < numbers.size(); i++) {
    min = i;
    for (j = i + 1; j < numbers.size(); j++) {
      if (numbers[j] < numbers[min]) min = j;
    }
    temp = numbers[i];
    numbers[i] = numbers[min];
    numbers[min] = temp;
    temp2 = numbers1[i];
    numbers1[i] = numbers1[min];
    numbers1[min] = temp2;
  }
}
int main() {
  long long k, n, count = 1;
  string s, s2, s3, s4;
  char c;
  long long a, b, w, d, f, g;
  vector<long long> v1;
  vector<string> s1;
  vector<string> v;
  map<int, int> m;
  for (int i = 1; i < 10; i++) {
    m[i] = 4;
  }
  m[10] = 15;
  cin >> n;
  if (n == 21)
    cout << 4;
  else if (n <= 10 || n > 20)
    cout << 0;
  else
    cout << m[n - 10];
}
