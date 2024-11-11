#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int Q, doubles, lengths, dat[1000009], tmp[1000009], arrays[1000009]; string S, T;
bool compare_suffix(int i, int j) {
	if (dat[i] == dat[j]) {
		int ri = (i + doubles <= lengths ? dat[i + doubles] : -1);
		int rj = (j + doubles <= lengths ? dat[j + doubles] : -1);
		return ri < rj;
	}
	return dat[i] < dat[j];
}
void suffix_array() {
	lengths = S.size();
	for (int i = 0; i <= lengths; i++) arrays[i] = i, dat[i] = i < lengths ? S[i] : -1;
	for (doubles = 1; doubles <= lengths; doubles <<= 1) {
		sort(arrays, arrays + lengths + 1, compare_suffix);
		tmp[arrays[0]] = 0;
		for (int i = 1; i <= lengths; i++) tmp[arrays[i]] = tmp[arrays[i - 1]] + (compare_suffix(arrays[i - 1], arrays[i]) ? 1 : 0);
		for (int i = 0; i <= lengths; i++) dat[i] = tmp[i];
	}
}
int main() {
	cin >> S >> Q;
	suffix_array();
	for (int i = 0; i < Q; i++) {
		cin >> T;
		int l = 0, r = S.size() + 1; bool flag = false;
		while (r - l > 1) {
			int m = (l + r) / 2;
			string S1 = S.substr(arrays[m], T.size());
			if (S1 == T) {
				flag = true; break;
			}
			if (S1 < T) l = m;
			else r = m;
		}
		printf(flag ? "1\n" : "0\n");
	}
}