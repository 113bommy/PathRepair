from collections import defaultdict
dic = defaultdict(int)
N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
for x,y in zip(A,B):
  dic[x] += 1
  dic[y] += 1
L = list(dic.values())
MAX = max(L)
if MAX > N:
  print("No"); exit()
INF = float("inf")
dicA_min = defaultdict(lambda: INF); dicA_max = defaultdict(lambda: 0)
dicB_min = defaultdict(lambda: INF); dicB_max = defaultdict(lambda: 0)
for i in range(N):
  dicA_min[A[i]] = min(dicA_min[A[i]],i)
  dicA_max[A[i]] = max(dicA_max[A[i]],i)
  dicB_min[B[i]] = min(dicB_min[B[i]],i)
  dicB_max[B[i]] = max(dicB_max[B[i]],i)
#print(dicA_min,dicA_max)
L = list(dicB_min.keys())
mink = -INF
maxk = INF
Flag = False
for t in L:
  if dicA_min[t] == INF:
    continue
  mink = max(dicA_max[t]-dicB_min[t]+1,mink)
  maxk = min(dicA_min[t]+N-dicB_max[t]-1,maxk)
  Flag = True
if not Flag:
  print("Yes")
  print(*B)
  exit()
#print(mink,maxk)
if mink >= 0:
  ans = B[-mink:] + B[:-mink]
else:
  ans = B[-mink:] + B[:-mink]
print("Yes")
print(*ans)