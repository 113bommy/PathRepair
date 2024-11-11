#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int yu=n%100;
	int zhang=n/100;
	if(yu<=zhang*5)
	cout << 1 << endl;
	else
	cout << 0 << endl;
	return 0;
}