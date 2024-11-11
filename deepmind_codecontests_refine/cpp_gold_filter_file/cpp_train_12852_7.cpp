#include <bits/stdc++.h>
template <class Elem>
std::ostream& operator<<(std::ostream& os, const std::list<Elem>& vec) {
  for (typename std::list<Elem>::const_iterator ii = vec.begin();
       ii != vec.end(); ++ii) {
    os << *ii << " ";
  }
  return os;
}
template <class Elem>
std::ostream& operator<<(std::ostream& os, const std::vector<Elem>& vec) {
  for (int i = 0; i < (int)vec.size(); i++) {
    os << vec[i] << " ";
  }
  return os;
}
template <class Elem>
std::istream& operator>>(std::istream& is, std::vector<Elem>& vec) {
  for (int i = 0; i < (int)vec.size(); i++) {
    is >> vec[i];
  }
  return is;
}
template <class Elem>
std::ostream& operator<<(std::ostream& os, const std::set<Elem>& vec) {
  for (typename std::set<Elem>::const_iterator ii = vec.begin();
       ii != vec.end(); ii++) {
    os << *ii << " ";
  }
  return os;
}
template <class Elem1, class Elem2>
std::ostream& operator<<(std::ostream& os, const std::map<Elem1, Elem2>& vec) {
  for (typename std::map<Elem1, Elem2>::const_iterator ii = vec.begin();
       ii != vec.end(); ii++) {
    os << "(" << ii->first << "," << ii->second << ") ";
  }
  return os;
}
template <class Elem1, class Elem2>
std::ostream& operator<<(std::ostream& os,
                         const std::multimap<Elem1, Elem2>& vec) {
  for (typename std::multimap<Elem1, Elem2>::const_iterator ii = vec.begin();
       ii != vec.end(); ii++) {
    os << "(" << ii->first << "," << ii->second << ") ";
  }
  return os;
}
template <class Elem>
bool operator==(const std::set<Elem>& vec1, const std::set<Elem>& vec2) {
  if (vec1.size() != vec2.size()) return false;
  typename std::set<Elem>::const_iterator ii1 = vec1.begin();
  typename std::set<Elem>::const_iterator ii2 = vec2.begin();
  for (; ii1 != vec1.end(); ii1++, ii2++) {
    if (*ii1 != *ii2) return false;
  }
  return true;
}
template <class Elem>
bool operator!=(const std::set<Elem>& vec1, const std::set<Elem>& vec2) {
  return !operator==(vec1, vec2);
}
using namespace std;
inline string trim(const string& cstr) {
  string str(cstr);
  char spaces[] = " \t\r\n";
  size_t pos = str.find_first_not_of(spaces);
  if (pos == string::npos) return string("");
  str = str.substr(pos);
  pos = str.find_last_not_of(spaces);
  str = str.substr(0, pos + 1);
  return str;
}
inline void skipWhiteSpaces(std::istream& input, const string whites) {
  char c;
  do {
    input.get(c);
  } while (!input.eof() && whites.find(c) < whites.size());
  if (!input.eof()) {
    input.unget();
  }
}
inline size_t nonWhite(const string& string, bool first) {
  char white[] = " \t";
  size_t pos;
  if (first) {
    pos = string.find_first_not_of(white);
  } else {
    pos = string.find_last_not_of(white);
  }
  return pos;
}
inline std::pair<string, string> split(const string& name,
                                       const string& separator = " \t",
                                       bool first = true) {
  size_t pos;
  string str(name);
  if (first) {
    pos = str.find_first_not_of(separator);
    if (pos == string::npos) return std::make_pair(string(""), string(""));
    str = str.substr(pos, str.size() - pos);
    pos = str.find_first_of(separator);
  } else {
    pos = str.find_last_not_of(separator);
    if (pos == string::npos) return std::make_pair(string(""), string(""));
    str.erase(pos + 1);
    pos = str.find_last_of(separator);
  }
  if (pos == string::npos) {
    return std::make_pair(trim(str), string(""));
  }
  string firstI = str.substr(0, pos);
  pos = str.find_first_not_of(separator, pos);
  if (pos == string::npos) {
    return std::make_pair(trim(firstI), string(""));
  }
  string secondI = str.substr(pos, name.size() - pos + 1);
  return std::make_pair(trim(firstI), trim(secondI));
}
inline std::pair<string, string> splitFileName(const string& filename) {
  return split(filename, ".", false);
}
inline std::vector<string> splitAll(const string& cstr,
                                    const string& separator = " \t") {
  std::vector<string> words;
  string str(cstr);
  size_t pos = str.find_first_of(separator);
  while (pos != string::npos && pos < str.length()) {
    string word = str.substr(0, pos);
    if (!word.empty()) {
      words.push_back(word);
    }
    while (pos < str.length() && separator.find(str.at(pos)) != string::npos)
      pos++;
    if (pos < str.length()) {
      str = str.substr(pos, str.size() - pos);
      pos = str.find_first_of(separator);
    } else {
      str = "";
    }
  }
  if (!str.empty()) words.push_back(str);
  return words;
}
inline unsigned long long gcd(unsigned long long a, unsigned long long b) {
  if (b == 0) return a;
  unsigned long long c;
  while (1) {
    c = a % b;
    if (c == 0) return b;
    a = b;
    b = c;
  }
}
inline unsigned long long lcm(unsigned long long a, unsigned long long b) {
  return a / gcd(a, b) * b;
}
struct TaskB {
  int n;
  int k;
  vector<int> f;
  void readInput(std::istream& input) {
    input >> n >> k;
    f.resize(n);
    input >> f;
  }
  map<int, int> fn;
  void solve(std::ostream& output, std::ostream& log) {
    for (int i = 0; i < n; i++) {
      fn[f[i]]++;
    }
    int s = 0;
    int sum = 0;
    log << n << " " << k << endl;
    log << fn << endl;
    for (map<int, int>::reverse_iterator ii = fn.rbegin(); ii != fn.rend();
         ++ii) {
      do {
        int cc = min(s, (*ii).second);
        (*ii).second -= cc;
        s -= cc;
        if (s == 0 && (*ii).second > 0) {
          s += k;
          sum += ((*ii).first - 1) * 2;
        }
      } while ((*ii).second > 0);
    }
    output << sum << endl;
  }
};
void taskB(std::istream& iStream, std::ostream& oStream, std::ostream& log) {
  int nTestCases;
  nTestCases = 1;
  for (int t = 0; t < nTestCases; t++) {
    TaskB task;
    task.readInput(iStream);
    task.solve(oStream, log);
  }
}
std::ostream cnull(0);
int main() {
  taskB(std::cin, std::cout, cnull);
  return 0;
}
