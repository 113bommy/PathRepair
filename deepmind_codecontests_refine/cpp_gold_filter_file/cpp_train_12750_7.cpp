#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int MAX = 1e9 + 5;
int n;
char c;
vector<int> v;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf(" %c", &c);
    if (c == '4')
      v.push_back(2), v.push_back(2), v.push_back(3);
    else if (c == '6')
      v.push_back(5), v.push_back(3);
    else if (c == '8')
      v.push_back(2), v.push_back(2), v.push_back(2), v.push_back(7);
    else if (c == '9')
      v.push_back(3), v.push_back(3), v.push_back(2), v.push_back(7);
    else if (c > '1')
      v.push_back(c - '0');
  }
  sort(v.begin(), v.end(), greater<int>());
  for (__typeof(v.begin()) it = v.begin(); it != v.end(); it++) cout << *it;
  cout << '\n';
  return 0;
}
