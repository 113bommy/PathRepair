#include<iostream>
#include<sstream>
#include<cmath>
using namespace std;

class Parsing
{
private:
  string parse;
  int pos;
  int size;
  int x;
public:

  Parsing(string parse,int x):parse(parse),pos(0),x(x),size(0){}

  int StringToInt(string v)
  {
    int ret = 0;
    for(int i=0;i<v.size();i++)
      ret += (v[i]-'0')*(int)pow(10.0,v.size()-i-1);
    return ret;
  }

  string getCnt()
  {
    string v;
    while('0' <= parse[pos] && parse[pos] <= '9') 
      v += parse[pos++];
    return v;  
  }

  int getCntInt(){return StringToInt(getCnt());}

  string decode()
  {
    int power = getCntInt();
    if(parse[pos] == '(')
      pos++;
    else 
      {
	string mes,ret;
	while('A' <= parse[pos] && parse[pos] <= 'Z')	
	  mes += parse[pos++];
	
	for(int i=0;i<power;i++)
	  {
	    ret += mes;
	    if(ret.size() >= x)
	      break;
	  }
	return ret;	  
      }
    string message;
    while(('0' <= parse[pos] && parse[pos] <= '9') || ('A' <= parse[pos] && parse[pos] <= 'Z') )
      {
	if('0' <= parse[pos] && parse[pos] <= '9')
	  message += decode();
	else if('A' <= parse[pos] && parse[pos] <= 'Z')
	  message += parse[pos++];
      }  
    
    if(parse[pos] == ')')
      pos++;
    
    string ret;
    for(int i=0;i<power;i++)
      {
	ret += message,size += message.size();
	if(ret.size() >= x)
	  break;
      }
    return ret;
  }
  
  string exp()
  {
    string ret;
    for(;pos<parse.size();)
      {
	if('0' <= parse[pos] && parse[pos] <= '9')
	  ret += decode();
	else
	  ret += parse[pos++],size++;
	if(ret.size() >= x)
	  break;
      }
    return ret;
  }

  int getSize()
  {
    return size;
  }

};

int main()
{
  string Genome;  
  int pos;
  while(cin >> Genome >> pos, Genome != "0" || pos != 0)
    {
      Parsing par = Parsing(Genome,pos+1);
      string message = par.exp();
      if(message.size() <= pos)
	cout << 0 << endl;
	else
	  cout << message[pos] << endl;
    }
  return 0;
}