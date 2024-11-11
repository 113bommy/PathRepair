#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
    int N,M;
    cin >>N>>M;
    int A[N];
    for(int i=0;int<N;++i){
        cin >>A[i];
    }
    
    for(int k=1;k<M+1;++k){
        for(int a=0;a<N+1;++a){
    if(1<=a&&a<N){
        if(A[a]%k>A[a+1]%k){
            int temp = A[a];
            A[a]=A[a+1];
            A[a+1]=temp;
            
        }
        else{
        }
        }
    else{
        break;
    }
    }
    }
    
    for(int w=0;w<N;++w){
        cout <<A[w]<<endl;
    }
    return 0;
}