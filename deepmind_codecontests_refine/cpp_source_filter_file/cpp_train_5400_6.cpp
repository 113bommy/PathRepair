#include <iostream>
using namespace std;

int main()
{
 int n;
 cin >> n;
 long long int ans;
 for(int i=1; i<=n; int i++) ans *= i;

 cout << ans << '\n';

 return 0;
}