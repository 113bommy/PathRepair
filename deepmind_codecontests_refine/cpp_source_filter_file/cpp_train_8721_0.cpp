#include <iostream>
#include<cmath>
using namespace std;

int main() {
	int n, m, a[100],c=0,all=0;
	cin >> n, m;
	for (int i = 0; i < n; i++){
		cin>>a[i];
		all+=a[i];
	}
	for (int i = 0; i < n; i++){
		if(a[i]>=all/4.0/m)c++;
	}
	if (c >= m)cout << "Yes";
	else cot << "No";
} 