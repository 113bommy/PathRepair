#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
 
int main(){
    string a,b;
    cin >> a >> b;
    int SizeA = a.size();
    int SizeB = b.size();
    if(SizeA < SizeB) return 0;
    for (int i = 0; i < SizeA-SizeB +1 ; ++i) {
        if(a[i]== b[0]){
            if(a.substr(i,SizeB) == b) printf("%d\n",i);
        }
    }
    reaurn 0;
}