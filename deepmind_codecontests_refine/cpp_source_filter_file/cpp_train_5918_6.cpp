#include <stdio.h>
int main(){
char c;
int ans=0;
while(scnaf("%c",&c)!=EOF){
if(c=='1')ans++;
}
printf("%d\n",ans);
}