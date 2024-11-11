#include <iostream>
#include <complex>
using namespace std;
  
double cross(complex<double> A, complex<double> B){
	return (conj(A)*B).imag();
}
 
int main(){
    complex<double> Points[3], P;
    while(true){
        double x, y;
        for(int i=0; i<3; i++){
            cin >> x >> y;
            V[i] = {x, y};
        }
        cin >> x >> y;
        P = {x, y};
         
        if(!cin)break;
         
        int sum = 0;
        for(int i=0; i<3; i++){
            sum += cross(Points[(i+1)%3]-Points[i], (P-Points[i])) > 0;
        }
        cout << (sum==0 || sum==3? "YES": "NO") << endl;
    }
    return 0;
}
