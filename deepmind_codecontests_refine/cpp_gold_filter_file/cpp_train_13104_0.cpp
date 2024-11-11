#include <stdio.h>

int main(void)
{
int a[100];
int n;
int index;

while (1){
scanf("%d", &n);
if (n == -1) break;
index = 0;
do {
a[index++] = (n & 0x3);
n >>= 2;
} while (n != 0);

index--;
while (index >= 0){
printf("%d", a[index--]);
}

puts("");
}
}