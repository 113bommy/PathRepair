#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t startTime = clock();
  long long n;
  cin >> n;
  if (n % 2)
    cout << "white"
         << "\n"
         << "1 2"
         << "\n";
  else
    cout << "black"
         << "\n";
}
