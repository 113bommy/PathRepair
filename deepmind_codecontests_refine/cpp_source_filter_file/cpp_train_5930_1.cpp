include <iostream>

using namespace std;


int a, b;
int main(){
    while(cin >> a >> b, a || b){
        int c = b-a;
        int cnt1, cnt2, cnt3;
        cnt1 = cnt2 = cnt3 = 0;
        while(c/1000){
            c -= 1000;
            cnt1++;
        }
        while(c/500){
            c -= 500;
            cnt2++;
        }
        while(c/100){
            c -= 100;
            cnt3++;
        }
        cout << cnt3 << " " << cnt2 << " " << cnt1 << endl;
    }
    
}