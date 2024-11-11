#include<iostream>
#include<algorithm>
typedef long long ll;
using namespace std;

int main() {
	ll n,a,b;
	cin >> n >> a >>b;
	if((b-a)%2==0)cout << (b-a)/2 << endl;
	else cout << min(a-1,n-b)+(b-a-1)/2+1 << endl;
	
	return 0;
}	