N, X = list(map(int, input().split()))
x = list(map(int, input().split()))

D = [pow(i, 2) for i in range(1, N + 2)]

ok = N
ng = 1
List = [-1 for i in range(N + 1)]
while abs(ok - ng) > 2:
  LR = [(ok - ng) // 3 + ng, 2 * (ok - ng) // 3 + ng]
  Ans = [0, 0]
  for j in range(2):
    if List[LR[j]] != -1:
      Ans[j] = List[LR[j]]
      continue
    least = 0
    Ans[j] = X * (N + LR[j])
    cnt = -1
    t = 0
    flag = False
    for i in x[::-1]:
      if flag:
        Ans[j] += (D[least + 1] - D[least]) * x[cnt]    
      else:
        Ans[j] += (D[0] + D[1]) * x[cnt]
      cnt -= 1
      t += 1
      if t == LR[j]:
        t = 0
        least += 1
        flag = True
    List[LR[j]] = Ans[j]
  if Ans[0] < Ans[1]:
    ok = LR[1]
  else:
    ng = LR[0]
 
FA = 1e20
for j in range(ng, ok + 1):
  if List[j] != -1:
    FA = min(FA, List[j])
    continue
  least = 0
  Ans = X * (N + j)
  cnt = -1
  t = 0
  flag = False
  for i in x[::-1]:
    if flag:
      Ans += (D[least + 1] - D[least]) * x[cnt]    
    else:
      Ans += (D[0] + D[1]) * x[cnt]
    cnt -= 1
    t += 1
    if t == j:
      t = 0
      least += 1
      flag = True
  FA = min(FA, Ans)
print(FA)