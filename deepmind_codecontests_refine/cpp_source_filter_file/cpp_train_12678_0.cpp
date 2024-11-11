#include <iostream>

using namespace std;

int main(){
	long long n,a,b;
	cin >> n >> a >> b;
	long long k = n / (a+b);
	cout << k*a + max(a,n-k*(a+b))) << endl;
}