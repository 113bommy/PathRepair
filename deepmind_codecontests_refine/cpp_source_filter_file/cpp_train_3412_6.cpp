#include <iostream>
#include <cstdio>
using namespace std;
int n,d = 0;
int main(){
	cin >> n;
	for(int i = 1; i < n; i ++){
		d = (d * 10 + k) % mod;
		if(d == 0){
			printf("%d\n",i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}