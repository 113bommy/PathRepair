#include<bits/stdc++.h>
using namespace std;


int main(){
	long long n,a;
	cin >> n;
	a = n/11*2;
	if(n%11){
		a++;
		if(x%11>6) a++;
	}
	cout << a << endl;
	return 0;
}