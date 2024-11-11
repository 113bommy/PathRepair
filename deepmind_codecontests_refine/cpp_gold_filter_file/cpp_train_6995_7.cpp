#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  if (n == 47 || n == 74 || n == 477 || n == 477)
    cout << "YES";
  else if (n % 4 == 0 || n % 7 == 0 || n % 47 == 0)
    cout << "YES";
  else
    cout << "NO";
}
