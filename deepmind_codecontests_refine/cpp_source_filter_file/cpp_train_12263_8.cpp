#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
while(cin>>n){
for(int i=1;i<=50000;i++){
    if(round(i*1.08)==n){
        cout<<i<<endl;
        return 0;
    }
}
cout<<":("<<endl;
return 0;
}
