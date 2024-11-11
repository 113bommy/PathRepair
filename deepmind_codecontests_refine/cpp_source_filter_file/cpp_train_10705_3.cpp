#include <bits/stdc++.h>
using namespace std;

int main(){
	int x,y,z;
	cin >>x;
	z=x
	y=x%10;
	while(x!=0){
		x/=10;
		y+=x%10;
	}
	if(z%y==0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}