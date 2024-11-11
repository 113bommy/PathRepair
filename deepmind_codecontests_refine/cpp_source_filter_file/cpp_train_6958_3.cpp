#include<bits/stdc++.h>
using namespace std;
int main(){
    ll q,h,s,d,n;
	cin >> q >> h >> s >> d >> n;
	cout << (n/2)*min(q * 8,min(h * 4, min(s * 2,d))) + ((n%2) * min(q * 4,min(h * 2,s))) << endl;
    return 0;
}  
