#include<cassert>
#include<cstdio>
#include<map>
#include<iostream>
#include<cctype>
#include<cstdlib>
#include<cstring>

using namespace std;

char *p;
map<string,int> atomtbl;

int number() {
    int res = atoi(p);
    while(isdigit(*p)) p++;
    return res;
}
int atom() {
    string name;
    int n=1;
    name += *p++;
    if(islower(*p)) name += *p++;
    if(isdigit(*p)) n = number();

    return atomtbl.at(name) * n;
}
int molecule() {
    int res = 0;
    while(*p && *p != ')') {
        if(*p == '(') {
            p++;
            int w = molecule();
            assert(*p == ')');
            p++;
            assert(isdigit(*p));
            res += w * number();
        }else{
            res += atom();
        }
    }
    return res;
}

int main(void) {
    while(true) {
        char s[5];
        int n;
        scanf("%s",s);
        if(!strcmp(s, "END_OF_FIRST_PART")) break;

        scanf("%d",&n);
        string str = s;
        atomtbl[str] = n;
    }

    while(true) {
        char in[1000];
        scanf("%s", in);
        if(!strcmp(in, "0")) break;

        p = in;
        try {
            printf("%d\n",molecule());
        }
        catch(const out_of_range& oor) {
            printf("UNKNOWN\n");
        }
    }
    return 0;
}