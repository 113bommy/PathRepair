#include <iostream>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;
int main()
{
  int K, T;
  cin >> K >> T;
  int ma = -1;
  REP(i, T) {
    int a;
    cin >> a;
    ma = max(a, ma);
  }
  cout << max(ma - 1 - (K - ma), 0) << endl;
  return 0;
}