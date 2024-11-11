#include <bits/stdc++.h>
using namespace std;
vector<long long int> primeFactors(long long int n) {
  vector<long long int> a;
  while (n % 2 == 0) {
    a.push_back(2);
    n = n / 2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      a.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) a.push_back(n);
  return a;
}
vector<long long int> printDivisors(long long int n) {
  vector<long long int> v;
  for (long long int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        v.push_back(i);
      else {
        v.push_back(i);
        v.push_back(n / i);
      }
    }
  }
  return v;
}
long long int power(long long int a, long long int b, long long int m) {
  if (b == 0) {
    return 1;
  } else {
    long long int temp = power(a, b / 2, m);
    if (b % 2 == 0)
      return (temp * temp) % m;
    else
      return (((a * temp) % m) * temp) % m;
  }
}
string sconvert(long long int n) {
  stringstream ss;
  ss << n;
  string str = ss.str();
  return str;
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second > b.second);
}
template <typename KeyType, typename ValueType>
std::pair<KeyType, ValueType> get_max(const std::map<KeyType, ValueType> &x) {
  using pairtype = std::pair<KeyType, ValueType>;
  return *std::max_element(x.begin(), x.end(),
                           [](const pairtype &p1, const pairtype &p2) {
                             return p1.second < p2.second;
                           });
}
const long long int mod = 1e9 + 7;
long long modmul(long long a, long long b) {
  return ((a % mod) * (b % mod)) % mod;
}
long long modadd(long long a, long long b) {
  return ((a % mod) + (b % mod) + mod) % mod;
}
long long modsub(long long a, long long b) {
  return ((a % mod) - (b % mod) + mod) % mod;
}
void single() {
  int n;
  cin >> n;
  vector<long long int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  ;
  sort((arr).begin(), (arr).end());
  vector<long long int> values;
  long long int temp = 1;
  while (temp <= 1e9) {
    values.push_back(temp);
    temp *= 2;
  }
  map<long long int, int> m;
  for (int x : arr) m[x]++;
  long long int answer = 0;
  for (int i = 0; i < n; i++) {
    long long int current = arr[i];
    int flag = 0;
    for (int j = 0; j < values.size(); j++) {
      if (values[j] > current) {
        if (m[values[j] - current] != 0) {
          if (values[j] - current == current and m[values[j] - current] == 1) {
            continue;
          }
          flag = 1;
        }
      }
    }
    if (flag) answer++;
  }
  cout << n - answer << '\n';
  return;
}
void multiple() {
  int asdf;
  cin >> asdf;
  while (asdf--) {
    single();
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  ;
  single();
}
