#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    int num=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        num^=a[i];
    }
    
    for(int i=0;i<n;i++)
        cout<<num^a[i]<<" ";
    
    return 0;
}