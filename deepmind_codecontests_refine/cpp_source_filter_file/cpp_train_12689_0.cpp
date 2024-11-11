#include <iostream>
using namespace std;

int gcd(int m,int n){
	if(n==0)return m;
	
	return gcd(n,m%n);
}

int main(){
	int W,H,C;
	cin >> W >> H >> C;

	int g = gcd(W,H);

	cout << W*G*C/(g*g) << endl;	

	return 0;
}
