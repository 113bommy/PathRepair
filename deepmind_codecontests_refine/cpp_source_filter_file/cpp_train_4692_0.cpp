#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
	int n;
	cin >> n;
	double x[n],y[n];
	for(i=0;i<n;i++) cin >> x[i];
	for(i=0;i<n;i++) cin >> y[i];
	for(int i=1;i<=3;i++){
		double s = 0;
		for(int j=0;j<n;j++) s += pow(abs(x[j]-y[j]),i);
		s = pow(s,1.0/i);
		cout << setprecision(10) << s << endl;
	}
	double t = 0;
	for(int i=0;i<n;i++) if(t<abs(x[i]-y[i])) t = abs(x[i]-y[i]);
	cout << setprecision(10) << t << endl;
}