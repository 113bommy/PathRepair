n, m = map(int, input().split())

l = [input() +'_' +str(_) for _ in range(n)]

res = []
for i in range(m):
  m = '0'
  for j in range(n) :
    m = max(m,l[j][i])
  res += filter(lambda x : x[i] == m, l)

print(len(list(set(res))))