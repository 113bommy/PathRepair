#include <bits/stdc++.h>
using namespace std;
class child_t {
 public:
  int volume;
  int confidence;
  int runVolume;
  int id;
  child_t() {
    static int myId = 0;
    id = ++myId;
    volume = confidence = runVolume = 0;
  }
  friend istream& operator>>(istream& file, child_t& obj) {
    file >> obj.volume >> obj.runVolume >> obj.confidence;
    ;
    return file;
  }
};
int main() {
  int num;
  cin >> num;
  vector<child_t> children(num);
  for (auto& child : children) cin >> child;
  vector<int> answer;
  for (auto i = 0u; i < children.size(); ++i) {
    answer.push_back(children[i].id);
    int currentVolume = children[i].volume;
    for (auto j = i + 1; j < children.size() && currentVolume;
         ++j, --currentVolume)
      children[j].confidence -= currentVolume;
    for (auto j = i + 1; j < children.size();) {
      if (children[j].confidence < 0) {
        int runVolume = children[j].runVolume;
        children.erase(children.begin() + j);
        for (auto k = j; k < children.size(); ++k)
          children[k].confidence -= runVolume;
      } else
        ++j;
    }
  }
  cout << answer.size() << '\n';
  for (auto& x : answer) cout << x << ' ';
  cout << '\n';
  return 0;
}
