#include <stdio.h>
int main (){
char a[118];
for(int i=0;i<118;i++){
scanf('%1c',&a[i]);
}
printf("A'%1c'C",a[8]);

return 0;
}