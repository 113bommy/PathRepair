#include <bits/stdc++.h>
using namespace std;
int main(){
	int k, a, b;
	cin >> k >> a >> b;
	cout << (b/k-(a-1)/k)>0? "OK": "NG";
}