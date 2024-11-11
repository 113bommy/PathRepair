#include <iostream>
using namespace std;
int main() 
{
	string s;
	cin >> s;
	cout << (s=="abc"||s=="acb"||s=="bac"||s=="bca"||s=="cab"||s=="cba"|| ? "Yes" : "No") << endl;
	return 0;
}