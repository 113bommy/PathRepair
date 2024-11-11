#include <bits/stdc++.h>
using namespace std;

const int highest=100;

int gerden[11][11];

int main(){
    int d, w;
    while(cin >> d >> w){
        if(d==0 && w==0) break;
        for(int i=0; i<d; i++){
            for(int j=0; j<w; j++){
                cin >> gerden[i][j];
            }
        }

        int ans=0;
        for(int i=3; i<=d; i++){
            for(int j=3; j<=w; j++){    \\ 縦i横jの池候補
                for(int k=0; k<=d-i; k++){
                    for(int l=0; l<=w-j; l++){   \\ 池候補を縦横に動かす

                        int min_out=100, max_in=-1, capacity=0;
                        for(int m=k; m<i+k; m++){
                            for(int n=l; n<j+l; n++){   \\ 池かどうかを調べる(ついでに容量)
                                if(m==k || n==l || m==k+i-1 || n==l+j-1){
                                    if(gerden[m][n]<min_out){
                                        min_out = gerden[m][n];
                                    }
                                }else{
                                    capacity += highest - gerden[m][n];
                                    if(gerden[m][n]>max_in){
                                        max_in = gerden[m][n];
                                    }
                                }
                            }
                        }
                        if(max_in < min_out){
                            if(capacity-((100-min_out)*(i-2)*(j-2)) > ans ){
                                ans = capacity - ((100-min_out)*(i-2)*(j-2));
                            }
                        }

                    }
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}

