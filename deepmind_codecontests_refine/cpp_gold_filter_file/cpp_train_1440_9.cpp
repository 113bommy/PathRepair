#include<bits/stdc++.h>
using namespace std;
int main(){
int n,x;
cin >> n >> x;
int dor,mini=2<<21;
for(int i=0;i<n;i++){
cin >> dor;
x-=dor;
if(dor < mini)mini=dor;
}
cout << n+(x/mini) << endl;
return 0;
} 