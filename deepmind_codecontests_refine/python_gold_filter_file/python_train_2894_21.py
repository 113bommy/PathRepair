N, Q = map(int, input().split(" "))
 
ns= [list(map(int, input().split(" ")))  for _ in range(N-1)]
vs = [list(map(int, input().split(" ")))  for _ in range(Q)]

dic = [[] for _ in range(N)]
rlt = [0]*N


for i in range(N-1):
  dic[ns[i][0]-1] += [ns[i][1]-1]
  
for j in range(Q):
  rlt[vs[j][0]-1] += vs[j][1]
  
for k in range(N):
  for l in dic[k]:
    rlt[l] += rlt[k]
    
print(" ".join(map(str, rlt)))