#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;
	struct constraint {
		bool z;
		uint64_t v;
	};
	vector<constraint> rows(N);
	vector<constraint> cols(N);
	for (int i = 0; i < N; i++) cin >> rows[i].z;
	for (int j = 0; j < N; j++) cin >> cols[j].z;

	for (int i = 0; i < N; i++) cin >> rows[i].v;
	for (int j = 0; j < N; j++) cin >> cols[j].v;

	auto id = [](bool z) -> uint64_t { return z ? uint64_t(0) : ~uint64_t(0); };
	auto op = [](bool z, uint64_t a, uint64_t b) -> uint64_t { return z ? (a | b) : (a & b); };

	uint64_t row_accum[2] = {id(0), id(1)};
	for (int i = 0; i < N; i++) {
		for (int z = 0; z < 2; z++) {
			row_accum[z] = op(z, row_accum[z], rows[i].v);
		}
	}
	uint64_t col_accum[2] = {id(0), id(1)};
	for (int j = 0; j < N; j++) {
		for (int z = 0; z < 2; z++) {
			col_accum[z] = op(z, col_accum[z], cols[j].v);
		}
	}

	vector<bool> row_parity(N);
	{
		bool cur_parity[2] = {true, true};
		for (int i = 0; i < N; i++) {
			row_parity[i] = (cur_parity[rows[i].z] ^= 1);
		}
	}
	vector<bool> col_parity(N);
	{
		bool cur_parity[2] = {true, true};
		for (int j = 0; j < N; j++) {
			col_parity[j] = (cur_parity[cols[j].z] ^= 1);
		}
	}

	auto get_cell = [&](int i, int j) -> uint64_t {
		const auto& [rz, rv] = constraint(rows[i]);
		const auto& [cz, cv] = constraint(cols[j]);
		if (rz == cz) {
			return op(!rz, rv, cv);
		} else {
			if (row_parity[i] ^ col_parity[j]) {
				return op(!cz, cv, op(!rz, ~row_accum[cz], rv));
			} else {
				return op(!rz, rv, op(!cz, ~col_accum[rz], cv));
			}
		}
	};

	vector<vector<uint64_t>> ans(N, vector<uint64_t>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans[i][j] = get_cell(i, j);
		}
	}

	for (int i = 0; i < N; i++) {
		uint64_t v = id(rows[i].z);
		for (int j = 0; j < N; j++) {
			v = op(rows[i].z, v, ans[i][j]);
		}
		if (v != rows[i].v) {
			cout << -1 << '\n';
			exit(0);
		}
	}
	for (int j = 0; j < N; j++) {
		uint64_t v = id(cols[j].z);
		for (int i = 0; i < N; i++) {
			v = op(cols[j].z, v, ans[i][j]);
		}
		if (v != cols[j].v) {
			cout << -1 << '\n';
			exit(0);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ans[i][j] << " \n"[j+1==N];

	}

	return 0;
}
