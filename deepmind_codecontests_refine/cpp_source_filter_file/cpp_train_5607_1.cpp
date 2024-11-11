#include<stdio.h>
#include<algorithm>
using namespace std;
int s(int x,int y){
    if(x<=y) return y-x;
        else return x-y+2;
}
int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%d\n",min(s(x,y),min(s(-x,y)+1,min(s(x,-y)+1,s(-x,-y)+2))));
    return 0;
