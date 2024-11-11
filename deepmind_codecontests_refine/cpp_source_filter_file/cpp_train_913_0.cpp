#include <iostream>
#include <algorithm>
using namespace std;
double a[110],res = 0;
int main(){
	int i,n;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a + n);
	res = a[0];
	for(i=1;i<n;i++){
		res += (res + a[i])/2;
	}
	cout << res << endl;
	