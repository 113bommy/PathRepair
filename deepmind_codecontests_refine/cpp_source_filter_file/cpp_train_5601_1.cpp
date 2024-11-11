#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	double a,total=0;
	for(i=0;i<n;i++){
		cin >> a;
		total += 1/a;
	} 
	cout << 1/total << endl;
	return 0;
}
