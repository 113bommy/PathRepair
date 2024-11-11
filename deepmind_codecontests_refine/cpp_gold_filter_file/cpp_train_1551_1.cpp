#include<iostream>
#include<cstring>

using namespace std;

string removedFirst(string str) {
  string ans;

  if(str.length() == 1) {
    return ans;
  }

  else {
    for(int i=1; i<str.length(); i++) {
      ans += str[i];
    }
    return ans;
  }
}

int main() {
  string str;
  getline(cin, str);
  while(str != "#") {
    char where = 'A';

    while(str.length() != 0) {
      char oldWhere = where;
      switch(where) {
      case 'A':
	if(str[0] == '0') {
	  where = 'X';
	}
	else {
	  where = 'Y';
	}
	break;
      case 'B':
	if(str[0] == '0') {
	  where = 'Y';
	}
	else {
	  where = 'X';
	}
	break;
      case 'X':
	if(str[0] == '1') {
	  where = 'Z';
	}
	break;
      case 'Y':
	if(str[0] == '0') {
	  where = 'X';
	}
	break;
      case 'Z':
	if(str[0] == '0') {
	  where = 'W';
	}
	else {
	  where = 'B';
	}
	break;
      case 'W':
	if(str[0] == '0') {
	  where = 'B';
	}
	else {
	  where = 'Y';
	}
      }
      str = removedFirst(str);
      if(where == oldWhere) {
	where = 'N';
	str.clear();
      }
    }

    if(where == 'B') {
      cout<<"Yes"<<endl;
    }
    else {
      cout<<"No"<<endl;
    }
    getline(cin, str);
  }
}