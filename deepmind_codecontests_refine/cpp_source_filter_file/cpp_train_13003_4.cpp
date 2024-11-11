#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    string s;
    int temp;
    whlie(true){
        getline(cin,s);
        if(s=="END OF INPUT")return 0;
        temp=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                printf("%d",temp);
                temp=0;
            }
            else temp++;
        }
        printf("%d\n",temp);
    }
}
