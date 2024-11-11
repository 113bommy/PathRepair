#include <bits/stdc++.h>
using namespace std;
void past_code();
bool marked[10];
void file() {}
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
bool de(long long arr[], long long x) {
  long long c = 0;
  for (long long i = 0; i < x - 1; i++) {
    if (arr[i] >= arr[i + 1]) c++;
  }
  if (c == x - 1)
    return false;
  else
    return true;
}
const double pi = 3.14159265358979323846;
bool cheak(int arr[], int x) {
  set<int> ch;
  for (int i = 0; i < x; i++) {
    ch.insert(arr[i]);
  }
  if (ch.size() == x)
    return false;
  else
    return true;
}
map<int, int> arr;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string str;
  cin >> str;
  int i = 0, j = n - 1;
  while (str[i] == '.') {
    i++;
  }
  while (str[j] == '.') {
    j--;
  }
  if (str[i] == 'R' && str[j] == 'R')
    cout << i + 1 << " " << j + 2 << endl;
  else if (str[i] == 'L' && str[j] == 'L')
    cout << j + 1 << " " << i - 1 + 1 << endl;
  else {
    cout << i + 1 << " ";
    while (str[j] == 'L') j--;
    cout << j + 1 << endl;
  }
  return 0;
}
