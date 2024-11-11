#include <bits/stdc++.h>
using namespace std;

char b[17] = "CODEFESTIVAL2016";

int main(){
    char a[17]; scanf("%s", a);
    for(int i = 0; i < 16; i++) if(a[i] != b[i]) cnt++;
    printf("%d\n", cnt);
}