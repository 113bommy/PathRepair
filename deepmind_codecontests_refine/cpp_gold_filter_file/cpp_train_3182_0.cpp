#include <bits/stdc++.h>
using namespace std;
typedef vector<pair<long long int, long long int> > pairsvector;
void printvictor(vector<long long int> v) {
  for (long long int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << endl;
}
void printPQ(priority_queue<long long int> pq) {
  while (!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
  }
  std::cout << '\n';
}
template <class T>
string toStr(const T &x) {
  stringstream s;
  s << x;
  return s.str();
}
template <class T>
long long int toInt(const T &x) {
  stringstream s;
  s << x;
  long long int r;
  s >> r;
  return r;
}
bool isprime(long long int n) {
  if (n == 2) return true;
  if (n < 2 || n % 2 == 0) return false;
  for (long long int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}
vector<long long int> generate_divisors(long long int n) {
  vector<long long int> v;
  long long int i;
  for (i = 1; i <= n; ++i)
    if (n % i == 0) v.push_back(i);
  return v;
}
long long int BinaryToDec(string binary) {
  long long int arr[binary.length()];
  long long int sum = 0;
  for (long long int i = 0; i < binary.length(); i++) arr[i] = pow(2, i);
  reverse(binary.begin(), binary.end());
  for (long long int i = 0; i < binary.length(); i++)
    if (toInt(binary[i]) == 1) sum += arr[i];
  return sum;
}
string DecToBinary(long long int decimal) {
  string binary = "";
  while (true) {
    if (decimal % 2 == 0)
      binary += '0';
    else
      binary += '1';
    if (decimal == 1) break;
    decimal /= 2;
  }
  reverse(binary.begin(), binary.end());
  return binary;
}
long long int gcd(long long int a, long long int b) {
  return b == 0 ? a : gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  std::vector<int> v(n);
  for (long long int i = 0; i < n; i++) cin >> v[i];
  std::vector<string> ss;
  for (long long int i = 0; i < n + 1; i++) {
    string temp;
    getline(cin, temp);
    ss.push_back(temp);
  }
  ss.erase(ss.begin());
  for (long long int i = 0; i < ss.size(); i++) {
    int counter = 0;
    for (int j = 0; j < ss[i].length(); j++) {
      if (ss[i][j] == 'a' || ss[i][j] == 'e' || ss[i][j] == 'i' ||
          ss[i][j] == 'o' || ss[i][j] == 'u' || ss[i][j] == 'y')
        counter++;
    }
    if (counter != v[i]) {
      cout << "NO"
           << "\n";
      return 0;
    }
  }
  cout << "YES"
       << "\n";
  return 0;
}
