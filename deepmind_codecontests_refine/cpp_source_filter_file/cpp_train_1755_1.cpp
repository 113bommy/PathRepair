#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int N;
    long long num = 0;
    cin>>N;
    int A[N],B[N];
    for(int i=0;i<N;i++){
        cin>>A[i]>>B[i];
    }
    for(int i=N-1;i>=0;i--){
        if((A[i]+num)%B[i]!=0){
            num+=B[i]-(A[i]+X)%B[i];
        }
    }
    cout <<num;
    return 0;
}