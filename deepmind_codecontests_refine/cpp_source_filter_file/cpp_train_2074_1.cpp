#include <iostream>
using namespace std;

josephus(int n, int k){
	if(n==1) return 0;
	return (josephus(n-1,k)+k)%n;
}

int main(){
	while(1){
		int n,k,m;
		cin >> n >> k >> m;
		if(n==0) break;
		cout << (josephus(n-1,k)+m)%n + 1 << endl;
	}
	return 0;
}