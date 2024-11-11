#include <iostream>
using namespace std;

int main(){
	long n,i,x[10000] mi,ma,l;
	l=0;
	cin >> n;
	mi = 1000000;
	ma = -1000000;
	for( i=0 ; i<n ; i++ ){
		cin >> x[i];
		ma=max(ma,x[i]);
		mi=min(mi,x[i]);
		l += x[i];
	}
	cout << mi <<' '<< ma <<' '<< l << endl;
	return 0;
}