#include <iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	if(a<=5) cout << 0;
	else if(a<=12) cout << b/2;
	else cout << b;
}