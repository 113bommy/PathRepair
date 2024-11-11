def process(k, d, n, x, m):
  d_mod = [di % m for di in d]
  sum_d_mod = sum(d_mod)
  inc_times1 = len([d_mod_i for d_mod_i in d_mod if d_mod_i])
  rem_d_mod = sum(d_mod[0:(n-1)%k])
  inc_times2 = len([d_mod_i for d_mod_i in d_mod[0:(n-1)%k] if d_mod_i])
  last = x + sum_d_mod * ((n-1) // k) + rem_d_mod
  first = x
  ans = inc_times1 * ((n-1) // k) + inc_times2
  ans -= last // m - first // m
  print(ans)


def main():
  k, q = map(int, input().split())
  d = list(map(int, input().split())) 
  for i in range(q):
    n, x, m = map(int, input().split())
    process(k, d, n, x, m)



if __name__ == "__main__" :
  main()