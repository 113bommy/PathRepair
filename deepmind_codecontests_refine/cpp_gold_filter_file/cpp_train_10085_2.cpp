#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
/*
vector<string> split(const string& input, char delimiter)
{
  istringstream stream(input);

  string field;
  vector<string> result;
  while (getline(stream, field, delimiter)) {
    result.push_back(field);
  }
  return result;
}
*/
int main() {
  string str, word;
  int i = 0;

  getline(cin, str);
  while(str[i] != '\0'){
    if(str[i] == '.' || str[i] == ',')
      str[i] = ' ';
    i++;
  }

/*
  for (const string& s : split(str, ' ')) {
    int size = s.size();
    if(size > 2 && size < 7) {
      cout << s << ' ';
    }
  }
 */
    
  stringstream ss(str);
  
    i=0;
  while (ss >> word) {
    int len = word.length();
      if(len>=3&&len<=6){
        if(i==0){cout<<word;i++;}
        else    cout<<' '<<word;
    }
  }
    
  cout << endl;
  return 0;
}
