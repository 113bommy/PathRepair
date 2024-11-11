#include <iostream>
#define MAX 5000
using namespace std ;

int a[40],b[40],c[40],n,ma,mb,opt;
int search(int sumA, int sumB, int sumC, int st){
    if(sumC>=opt) return opt;  
    if((sumA+a[st])*mb==(sumB+b[st])*ma){
        opt=min(opt,sumC+c[st]);
        if(st==n-1) return opt;
        return min(opt, search(sumA, sumB, sumC, st+1));
    }
    if(st==n-1) return opt;
    return min(opt, search(sumA, sumB, sumC, st+1), search(sumA+a[st], sumB+b[st], sumC+c[st], st+1));
}
int main(void){
    opt=MAX;
    cin>>n>>ma>>mb;
    for(int i=0;i<n;i++) cin>>a[i]>>b[i]>>c[i];
    opt=search(0,0,0,0);
    if(opt>=MAX) opt=-1;
    cout<<opt<<endl;
}