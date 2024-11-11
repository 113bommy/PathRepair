#include<string>
#include<iostream>
using namespace std;


int main(){
  string str;
  cin >> str;
  int q;
  cin >> q;

  for (int i = 0; i < q; i++){
    string com, strpr, p;
    int a, b;
    cin >> com >> a >> b;
    if (com == "print") cout << str.substr(a, b-a+1) << endl;
    else if (com == "reverse") {
      string tmp = str.substr(a, b-a+1);
      int n = tmp.size();
      for (int i = 0; i < n; i++){str[i+a] = tmp[n-i-1];}
      }
    else if (com == "replace") {cin >> p; str = str.replace(a, b-a+1, p);}

}

return 0;
}