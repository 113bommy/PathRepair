#include <cstdio>

int main(){
    char S[4];
    scanf("%s", S);
    printf("%d\n", 700+100*((S[0]=='o')+(S[1]=='o')+(S[2]=='o')));
    return 0;
}