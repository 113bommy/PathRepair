#include <bits/stdc++.h>
using namespace std;

int arr[200000];
int n;

int main(){
	cin >> n;
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		sum ^= arr[i];
	}
	for(int i = 0; i < n; i++)
		cout << (sum ^ arr[i]) << ' ';
	return cout << endl, 0;
}