#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int k;
  cin >> k;
  long long int s;
  s = ((long long int)1 << 18);
  cout << 2 << " " << 3 << endl;
  cout << s + k << " " << s << " "
       << "0" << endl;
  cout << k << " " << s + k << " " << s + k << endl;
}
