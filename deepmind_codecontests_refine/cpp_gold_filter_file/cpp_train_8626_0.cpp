#include <iostream>
using namespace std;

int main(){
	int n;
	const int max = 50000;
	int a[max];
	a[1] = 0;
	for(int i = 2; i < max; i++) a[i] = 1;
	for(int i = 2; i * i <= max; i++){
		for(int j = 2; j*i <= max; j++){
			a[i*j] = 0;
		}
	}
	while(cin >> n){
		if(n == 0) break;
		int count = 0;
		if(n % 2 == 1){
			if(a[n-2]){
				cout << 1 << endl;
			}else{
				cout << 0 << endl;
			}
		}else{
			for(int i = 2; i <= n-i; i++)
				if(a[i] && a[n-i])
					count++;
			cout << count <<endl;
		}
	}
	return 0;
}