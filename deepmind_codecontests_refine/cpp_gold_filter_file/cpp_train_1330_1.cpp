#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin>>n;
    if(n%10==0|| n%10==6 || n%10==8 || n%10==1)cout<<"pon";
    else if(n%10==3)cout<<"bon";
    else cout<<"hon";
    
}