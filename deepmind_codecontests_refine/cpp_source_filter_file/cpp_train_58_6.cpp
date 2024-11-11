#include <bits/stdc++.h>
using namespace std;
int *Memory;
int t, m;
int CountEmpty(int currIndex) {
  int c = 1;
  for (int i = currIndex + 1; i < m; i++) {
    if (Memory[i] == -1)
      c++;
    else
      break;
  }
  return c;
}
int main() {
  cin >> t >> m;
  Memory = new int[m];
  for (int i = 0; i < m; i++) Memory[i] = -1;
  int a = 1;
  vector<string> answers;
  string temp = "";
  string last = "";
  char *temp_string = new char[150];
  temp_string[0] = '/0';
  cin.ignore(1);
  for (int i = 0; i < t; i++) {
    cin.getline(temp_string, 150);
    temp = temp_string;
    if (temp == "defragment" && temp == last) continue;
    last = temp;
    if (temp[0] == 'a') {
      bool allocated = false;
      int sizeToalloc =
          atoi(temp.substr(temp.find_first_of(' '), temp.length()).c_str());
      for (int i = 0; i < m; i++) {
        if (Memory[i] == -1) {
          if (CountEmpty(i) >= sizeToalloc) {
            for (int j = 0; j < sizeToalloc; j++) Memory[i++] = a;
            allocated = true;
            break;
          }
        }
      }
      if (allocated) {
        answers.push_back(to_string((long long)a));
        a++;
      } else
        answers.push_back("NULL");
      continue;
    }
    if (temp[0] == 'e') {
      bool found = false;
      int e = atoi(temp.substr(temp.find_first_of(' '), temp.length()).c_str());
      if (e < 1 || e > m) {
        answers.push_back("ILLEGAL_ERASE_ARGUMENT");
        continue;
      }
      for (int i = 0; i < m; i++) {
        if (Memory[i] == e) {
          found = true;
          Memory[i] = -1;
        }
      }
      if (!found) answers.push_back("ILLEGAL_ERASE_ARGUMENT");
      continue;
    }
    if (temp[0] == 'd') {
      if (CountEmpty(0) == m) continue;
      int num = 0;
      int *Temp = new int[m];
      for (int i = 0; i < m; i++) Temp[i] = Memory[i];
      for (int i = 0; i < m; i++) Memory[i] = -1;
      int j = 0;
      for (int i = 0; i < m; i++)
        if (Temp[i] != -1) Memory[j++] = Temp[i];
      continue;
    }
  }
  for (int i = 0; i < answers.size(); i++) cout << answers[i] << endl;
}
