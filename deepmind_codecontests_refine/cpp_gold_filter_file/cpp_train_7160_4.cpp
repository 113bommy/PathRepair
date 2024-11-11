#include <iostream>
using namespace std;

bool kaibun(string s) {
  string t(s.rbegin(), s.rend());
  return s == t;
}

int main () {
  string s;
  cin >> s;
  
  int n = s.size();
  if (kaibun(s) && kaibun(s.substr(0, n/2)) && kaibun(s.substr(n/2+1))) {
    cout << "Yes" << endl;
  } else{
    cout << "No" << endl;
  }

}
