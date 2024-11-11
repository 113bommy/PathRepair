#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        if((108*i)/100==n){
            cout << i;
            return 0;
        }
    }
    cout << ":(";
}