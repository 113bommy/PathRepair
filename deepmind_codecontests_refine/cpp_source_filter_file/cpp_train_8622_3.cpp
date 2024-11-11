#include<iostream>
using namespace std;
int main(){
    bool f[100001]={};
    int c[100002]={};
    int N,L,R;
    //エラトステネスの篩
    for(int i=2;i<=100000;i++){
        if(f[i]==0){
            for(int j=i+i;j<=100000;j+=i){
                f[j]=true;
            }
        }
    }
    //
    for(int i=3;i<=100000;i+=2){
        if(f[i]==0&&f[(i+1)/2]==0)  c[i]++
    }
    for(int i=3;i<=100000;i++)  c[i]+=c[i-1];
    
    cin >> N;
    while(N--){
        cin >> L >> R;
        cout << c[R]-c[L-1] << "\n";
    }
}