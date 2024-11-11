#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n),n){
        int cnt = 0;
        bool flg = 0;
        while(1){
            if(n == 6174)break;
            if(n%1111 == 0){
                flg = 1;
                break;
            }
            int a[4]={0};
            a[0] = n/1000;
            a[1] = (n%1000)/100;
            a[2] = (n%100)/10;
            a[3] = n%10;
            int L[4],S[4];
            sort(a,a+4);
            for(int i = 0; i < 4; i++){
                L[3-i] = S[i] = a[i];
            }
            int l=0,s=0;
            for(int i = 0; i < 4; i++){
                l += L[3-i] * pow(10,i);
                s += S[3-i] * pow(10,i);
            }
            n = l - s;
            cnt++;
        }
        if(flg)puts("NA");
        else printf("%d\n",cnt);
    }
	return 0;
}