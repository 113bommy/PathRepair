N, M = map(int,input().split())

v = [i for i in range(1,N+1)]
e = [[]]*(N+1)
for i in range(M):
  a, b = map(int,input().split())
  e[a] = e[a] + [b]
  e[b] = e[b] + [a]

def dfs(v, e):
  for num in v:
    if(len(e[num]) == 1):
      tmp_num = e[num][0]
      v.remove(num)
      e[num] = []
      e[tmp_num].remove(num)
      #print(e,v)
      return dfs(v, e)+1
  return 0
print(dfs(v, e))