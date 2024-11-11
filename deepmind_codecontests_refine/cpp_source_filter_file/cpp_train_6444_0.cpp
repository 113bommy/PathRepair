#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
    int a,b,c,d,e,f;
    cin >>a>>b>>c>>d>>e>>f;
    score[]={a,b,c,d};
    sort(score,score+4);
    score2[]={e,f};
    sort(score2,score2+2);
    cout <<score[1]+score[2]+score[3]+score2[1]<<endl;
    
    return 0;
}