#include<bits/stdc++.h>

using namespace std;

int main() {
int n;
while(cin>>n,n){
int cnt=0,v;
bool f = false;
for(int i=0;i<n;++i) {
cin >> v;
if( v >= 2) f = true;
if( v ) ++cnt;
}
if(!f)puts("NA");
else cout << cnt + 1 << endl;
}
return 0;
}