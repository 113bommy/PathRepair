#include <bits/stdc++.h>
using namespace std;
enum class Heap { first, second };
int main() {
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> dic(101);
  for (int i = 0; i < 2 * n; i++) {
    int cube;
    cin >> cube;
    dic[cube].push_back(make_pair(cube, i));
  }
  vector<pair<int, int>> distinctEls;
  vector<pair<int, int>> sameEls;
  for (auto it = dic.begin(); it != dic.end(); it++) {
    if (it->size() == 1) {
      distinctEls.push_back(*it->begin());
    } else if (it->size() > 1) {
      for (auto jt = it->begin(); jt != it->end(); jt++) {
        sameEls.push_back(*jt);
      }
    }
  }
  vector<int> results(2 * n);
  vector<vector<int>> heaps(2);
  int heap = 0;
  for (auto it = sameEls.begin(); it != sameEls.end(); it++) {
    results[it->second] = heap + 1;
    heaps[heap].push_back(it->first);
    heap = (heap + 1) % 2;
  }
  if (heaps[0].size() == heaps[1].size()) {
    int i = 0;
    for (; i < distinctEls.size() / 2; i++) {
      heaps[0].push_back(distinctEls[i].first);
      results[distinctEls[i].second] = 1;
    }
    for (; i < distinctEls.size(); i++) {
      heaps[1].push_back(distinctEls[i].first);
      results[distinctEls[i].second] = 2;
    }
  } else if (heaps[0].size() > heaps[1].size()) {
    int i = 0;
    while (heaps[0].size() > heaps[1].size()) {
      heaps[1].push_back(distinctEls[i].first);
      results[distinctEls[i].second] = 2;
      i++;
    }
    int noAssignedEls = i;
    for (; i < (distinctEls.size() - noAssignedEls) / 2; i++) {
      heaps[0].push_back(distinctEls[i].first);
      results[distinctEls[i].second] = 1;
    }
    for (; i < distinctEls.size(); i++) {
      heaps[1].push_back(distinctEls[i].first);
      results[distinctEls[i].second] = 2;
    }
  } else if (heaps[0].size() < heaps[1].size()) {
    int i = 0;
    while (heaps[0].size() < heaps[1].size()) {
      heaps[0].push_back(distinctEls[i].first);
      results[distinctEls[i].second] = 1;
      i++;
    }
    int noAssignedEls = i;
    for (; i < (distinctEls.size() - noAssignedEls) / 2; i++) {
      heaps[0].push_back(distinctEls[i].first);
      results[distinctEls[i].second] = 1;
    }
    for (; i < distinctEls.size(); i++) {
      heaps[1].push_back(distinctEls[i].first);
      results[distinctEls[i].second] = 2;
    }
  }
  int first = 1;
  int second = 1;
  for (int i = 1; i < heaps[0].size(); i++) {
    if (heaps[0][i - 1] != heaps[0][i]) first++;
  }
  for (int i = 1; i < heaps[1].size(); i++) {
    if (heaps[1][i - 1] != heaps[1][i]) second++;
  }
  cout << first * second << endl;
  for (auto it = results.begin(); it != results.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}
