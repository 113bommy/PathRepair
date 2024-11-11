#include <bits/stdc++.h>
struct Station {
  int32_t index;
  int32_t* data;
  Station() {}
  Station(int32_t index_, int32_t* data_) {
    index = index_;
    data = data_;
  }
};
class StationsComparator {
 public:
  int32_t number_of_candidates;
  int32_t proposed_candidate;
  StationsComparator(int32_t number_of_candidates_,
                     int32_t proposed_candidate_) {
    number_of_candidates = number_of_candidates_;
    proposed_candidate = proposed_candidate_;
  }
  bool operator()(Station& station1, Station& station2) {
    int32_t diff1 = station1.data[number_of_candidates - 1] -
                    station2.data[proposed_candidate];
    int32_t diff2 = station2.data[number_of_candidates - 1] -
                    station2.data[proposed_candidate];
    return diff1 > diff2;
  }
};
int main() {
  int32_t number_of_candidates, number_of_stations;
  std::cin >> number_of_candidates >> number_of_stations;
  std::vector<Station> votes(number_of_stations);
  int32_t* votes_per_candidate = new int32_t[number_of_candidates];
  for (int32_t i = 0; i < number_of_candidates; i++) votes_per_candidate[i] = 0;
  for (int32_t i = 0; i < number_of_stations; i++) {
    votes[i].index = i;
    votes[i].data = new int32_t[number_of_candidates];
    for (int32_t j = 0; j < number_of_candidates; j++) {
      std::cin >> votes[i].data[j];
      votes_per_candidate[j] += votes[i].data[j];
    }
  }
  int32_t answer = INT32_MAX;
  std::vector<int32_t> cancelled_stations;
  for (int32_t i = 0; i < number_of_candidates - 1; i++) {
    std::sort(votes.begin(), votes.end(),
              StationsComparator(number_of_candidates, i));
    int32_t to_cancel =
        votes_per_candidate[number_of_candidates - 1] - votes_per_candidate[i];
    int32_t cancelled_diff = 0;
    int32_t index_to_cancel = 0;
    while (cancelled_diff < to_cancel) {
      cancelled_diff += votes[index_to_cancel].data[number_of_candidates - 1] -
                        votes[index_to_cancel].data[i];
      index_to_cancel++;
    }
    if (index_to_cancel < answer) {
      answer = index_to_cancel;
      cancelled_stations.clear();
      for (int32_t j = 0; j < index_to_cancel; j++)
        cancelled_stations.push_back(votes[j].index);
    }
    answer = std::min(answer, index_to_cancel);
  }
  std::cout << answer << "\n";
  for (int32_t i = 0; i < cancelled_stations.size(); i++) {
    std::cout << cancelled_stations[i] + 1 << " ";
  }
  return 0;
}
