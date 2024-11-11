#include <bits/stdc++.h>
using namespace std;
void _a_b_c_d_e_f_g_h_i_j_k_l_m_n_o_p_q_r_s_t_u_v_w_x_y_z() {
  long long n, k, q = 0, c = 0;
  string s;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<double> v(n + 1);
  double x = 0, y = 0;
  v[0] = x;
  for (int i = 0; i < n; i++) v[i + 1] = v[i] + a[i];
  for (int i = k; i <= n; i++)
    for (int j = 0; j <= n - k; j++) {
      double o = (double)((v[j + k] - v[j])) / (double)k;
      x = max(o, x);
    }
  cout << fixed << setprecision(12) << x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  while (t--) {
    _a_b_c_d_e_f_g_h_i_j_k_l_m_n_o_p_q_r_s_t_u_v_w_x_y_z();
  }
  return 0;
}
