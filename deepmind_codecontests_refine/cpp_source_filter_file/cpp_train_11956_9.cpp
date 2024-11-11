#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n, k, x;
	int sum = 0;
	cin >> n >> k;
	for(int i=0; i<n; i++){
		cin >> x;
		sum += 2 * min(x, k - x)
	}
	cout << sum;
}