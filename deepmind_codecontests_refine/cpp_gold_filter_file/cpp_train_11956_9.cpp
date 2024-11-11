#include <algorithm>
#include <iostream>
using namespace std;

int main(){
	int N, K, x, a=0;
	cin >> N >> K;
	for(int i=0; i<N; i++){
		cin >> x;
		a += 2*min(x, K-x);
	}
	cout << a;
}