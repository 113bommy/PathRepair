#include<bits/stdc++.h>
using namespace std;
int main(){
	int A,B;
	cin>>A>>B;
	if(max(A,B)>8)
		cout<<":(";
	else
		cout<<"Yay!";
	return 0;
}