#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    cin >> a[0];
    int sum = a[0];
    for(int i=1;i<n;i++){
        cin >> a[i];
        sum ^= a[i];
    }
    for(int i=0;i<n;i++)cout << sum^a[i] << " ";
}