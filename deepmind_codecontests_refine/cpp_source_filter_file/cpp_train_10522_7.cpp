#include<bits/stdc++.h>
using namespace std;
 
signed main(){
 int a,b,c;
 while(scanf("%d%d%d",&a,&b,&c),(a+1)||(b+1)||(c+1)){
     if((a+1)&&(b+1)&&a+b>=30){
	 if(a+b>79)printf("A\n");
	 else if(a+b>64)printf("B\n");
	 else f(a+b>49)printf("C\n");
	 else if(c>49)printf("C\n");
	 else printf("D\n");
	 }
	 else printf("F\n");
     }
}