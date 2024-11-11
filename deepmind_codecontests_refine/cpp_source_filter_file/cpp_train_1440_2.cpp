#include<bits/stdc++.h>
using namespace std;
int main(){
int n,x;
cin >> n >> x;
int dor,mini=2<<21;
for(int i=0;i<n;i++){
cin >> dor;
x-=dor;
if(dor < mini)miini=dor;
}
cout << n+(x/miini) << endl;
return 0;
} 