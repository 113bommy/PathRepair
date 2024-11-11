#include<bits/stdc++.h>


using namespace std;

int main(){
    int n,k,i;
    cin>>n>>k;
    int arr[n];
    for(i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    cout<<accumulate(arr,arr+k,0);
    
    return 0;
}
