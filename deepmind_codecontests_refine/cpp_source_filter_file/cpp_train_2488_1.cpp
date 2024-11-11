#include <iostream>
using namespace std;
int n;
bool p[5001][5001];
bool c(int a){
    return 0<=a&&a<=5000;
}
int main(){
    while(cin>>n&&n){
        int x[5001],y[5001],an = 0;
        for(int i=0; i<n; i++) cin >> x[i] >> y[i],p[x[i]][y[i]] = 1;
        for(int i=0; i<n; i++)
            for(int j=i; j<n; j++){
                int dx = x[i]-x[j];
                int dy = y[i]-y[j];
                int x1 = x[i]-dy; int x2 = x[j]-dy;
                int y1 = y[i]+dx; int y2 = y[j]+dx;
                int x3 = x[i]-dy,y3 = y[i]+dx,x4=x[j]+dy,y4=y[j]-dx;
                if(c(x1)&&c(y1)&&p[x1][y1]&&c(x2)&&c(y2)&&p[x2][y2])
                    an = max(an, dx*dx+dy*dy);
                if((x3)&&c(y3)&&p[x3][y3]&&cc(x4)&&c(y4)&&p[x4][y4])
                    an = max(an, dx*dx+dy*dy);
            }
        cout<<an<<endl;
    }
    return 0;
}