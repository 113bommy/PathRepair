from collections import Counter
def get_par(x, par_lst):
  if x == par_lst[x]:
    return x
  ret = get_par(par_lst[x], par_lst)
  par_lst[x] = ret
  return ret

def main():
  while True:
    n, m = map(int, input().split())
    if n == 0:
      break
    par_lst = [i for i in range(n)]
    counter = Counter()
    flag = False
    if m == 0:
      print("yes")
      continue
    for _ in range(m):
      u, v = map(int, input().split())
      u -= 1
      v -= 1
      counter[u] += 1
      counter[v] += 1
      pu, pv = get_par(u, par_lst), get_par(v, par_lst)
      if pu == pv:
        flag = True
      else:
        par_lst[pu] = pv
    
    if counter.most_common()[0][1] > 2:
      flag = True
    if flag:
      print("no")
    else:
      print("yes")
main()
