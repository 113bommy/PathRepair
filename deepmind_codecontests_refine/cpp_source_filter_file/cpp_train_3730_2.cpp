#include <cstdio>

int main(){
    char S[4];
    scanf("%s", S);
    printf("%d\n", 700+100*(S[0]=='○'+S[1]=='○'+S[2]=='○'));
    return 0;
}