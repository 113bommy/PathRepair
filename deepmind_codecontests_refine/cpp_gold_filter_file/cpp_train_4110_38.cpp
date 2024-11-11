#include <bits/stdc++.h>
long long m1, v1, m_point, v_point, m_time, v_time;
int main() {
  scanf("%d %d %d %d", &m_point, &v_point, &m_time, &v_time);
  m1 = std::max(3 * m_point / 10, m_point - m_point / 250 * m_time);
  v1 = std::max(3 * v_point / 10, v_point - v_point / 250 * v_time);
  if (m1 > v1)
    printf("%s", "Misha");
  else if (v1 > m1)
    printf("%s", "Vasya");
  else
    printf("%s", "Tie");
}
