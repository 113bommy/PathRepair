#include <bits/stdc++.h>
using namespace std;
long long W,a,b;
int main() {
	cin>>W>>a>>b;
	cout<<max(0,abs(a-b)-W)<<endl;
	return 0;
}