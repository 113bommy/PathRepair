#include <bits/stdc++.h>
using namespace std;
int dxx[] = {0, 0, 1, -1, -1, 1, -1, 1};
int dyy[] = {1, -1, 0, 0, -1, 1, 1, -1};
bool sortbysec(const pair<int, int>& a, const pair<int, int>& b) {
  return (a.second < b.second);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  if (n % 2)
    cout << 1 << '\n';
  else
    cout << 2 << '\n';
}
