#include<bits/stdc++.h>
using namespace std;
int main(){
char a[1001];
while(1){
scanf("%s", a);
if( a[0] == '0' ) break;
int sum = 0;
for (int i = 0; i < strlen(a); i++ ){
sum += (a[i]-'0');
}
printf("%d\n, sum);
}
return 0;
}