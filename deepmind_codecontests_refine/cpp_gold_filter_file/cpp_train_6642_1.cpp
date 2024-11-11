#include <bits/stdc++.h>
using namespace std;
int main() {

int a;
   cin >> a;
   if(1<=a/100&&a/100<=12){
if(1<=a%100&&a%100<=12){
cout <<"AMBIGUOUS" <<endl;
}
else{
  cout <<"MMYY" << endl;
    }
}
  else{
if(1<=a%100&&a%100<=12){
  cout << "YYMM" << endl;
}
else {
  cout << "NA"<< endl;
}
  }

}
