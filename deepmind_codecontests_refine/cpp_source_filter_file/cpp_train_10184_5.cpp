#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[3]ans;cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    ans=a[2]--a[0];
    cout<<ans<<endl;
	return 0;
}