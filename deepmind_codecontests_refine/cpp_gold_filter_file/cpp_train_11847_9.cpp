#include <iostream>

using namespace std;

int main()
{
  long n, a, b;
  cin >> n >> a >> b;
  
  if ((a+b) % 2)
    if (a+b < 1+n)
      a = 1 - a;
    else
      a = 2 * n + 1 - a;
      
  cout << (a > b ? (a-b)/2 : (b-a)/2) << endl;
}
