#include <iostream>
#include <algorithm>
using namespace std;

int d[3][3]={{0,4,5,1},{0,2,5,3},{4,2,1,3}};//d,u,l,r

void dice(int a[6], int n){
	int tmp = a[d[n][0]];
	a[d[n][0]] = a[d[n][1]];
	a[d[n][1]] = a[d[n][2]];
	a[d[n][2]] = a[d[n][3]];
	a[d[n][3]] = tmp;
}

int check(int a[6], int b[6]){
	for(int i = 0;i < 6;i++)if(a[i] != b[i])return 0;
	return 1;
}

int func(int a[6], int b[6]){
	for(int i = 0;i < 6;i++){
		for(int j = 0;j < 4;j++){
			dice(b, 0);
			if(check(a, b))return 1;
		}
		if(i%2 == 0)dice(b, 1);
		else{
			dice(b, 2);
		}
	}
	return 0;
}

int main(){
	int a[6], b[6];
	for(int i = 0;i < 6;i++)cin >> a[i];
	for(int i = 0;i < 6;i++)cin >> b[i];
	
	/*for(int i = 0;i < 6;i++)cout << a[i] << " ";
	cout << endl;
	for(int i = 0;i < 6;i++)cout << b[i] << " ";
	cout << endl;*/
	
	if(func(a, b))cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}