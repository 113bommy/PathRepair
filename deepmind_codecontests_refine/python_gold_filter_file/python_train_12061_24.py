N,W = map(int,input().split())
WV = [list(map(int,input().split())) for _ in range(N)]

Wdic = {}
for w in WV:
  if w[0] not in Wdic:
    Wdic[w[0]] = [w]
  else:
    Wdic[w[0]].append(w)

Wcount = [[0 for _ in range(2)] for _ in range(4)]
idx = 0
for k in Wdic.keys():
  Wcount[idx] = [k,len(Wdic[k])]
  idx += 1
#print(Wcount)

Wsum = {}
for k,v in Wdic.items():
  v.sort(key=lambda x:x[1], reverse = True)
  Wsum[k] = [v[0][1]]
  for i in range(1,len(v)):
    Wsum[k].append(Wsum[k][-1] + v[i][1])
#print(Wsum)

def check(i,j,k,l):
  ret = 0
  w = 0
  if i > 0 and Wcount[0][0] > 0:
    ret += Wsum[Wcount[0][0]][i-1]
    w += Wcount[0][0]*i
  if j > 0 and Wcount[1][0] > 0:
    ret += Wsum[Wcount[1][0]][j-1]
    w += Wcount[1][0]*j
  if k > 0 and Wcount[2][0] > 0:
    ret += Wsum[Wcount[2][0]][k-1]
    w += Wcount[2][0]*k
  if l > 0 and Wcount[3][0] > 0:
    ret += Wsum[Wcount[3][0]][l-1]
    w += Wcount[3][0]*l
  if w > W:
    ret = 0
  return ret

value = 0
for i in range(Wcount[0][1]+1):
  for j in range(Wcount[1][1]+1):
    for k in range(Wcount[2][1]+1):
      for l in range(Wcount[3][1]+1):
        value = max(value,check(i,j,k,l))
print(value)
