#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int n,x[100005],a=0;
	long long s[2];
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> x[i];
	}
	sort(x,x+n);
	for(int i=n-1;i>0;i--){
		if(x[i]==x[i-1]){
			s[a++]=x[i];
			i--;
			if(a==2){
				cout << s[0]*s[1] << endl;
				return 0;
			}
		}
	}
	cout << "0" << endl;
	return 0;
}