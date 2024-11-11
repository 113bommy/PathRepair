#include<iostream>
#include<string>
using namespace std;
int main(){
  string a;cin >> a;
  cout << ((a[0] != a[1] && a[1] != a[2] && a[2] != a[3]) ? "Good":"Bad") << endl;
}
