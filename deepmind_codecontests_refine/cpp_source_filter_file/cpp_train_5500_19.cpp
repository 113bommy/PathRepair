#include <bits/stdc++.h>
using namespace std;
int N,A = 0;
int main(){
	cin >> N >> A ;
	cout << (N % 500) <= A ? "Yes" : "No" << endl;
}