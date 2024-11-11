import bisect as bs
import sys

sys.setrecursionlimit(2*10**5+1)

def dfs(i, nbr, A, prv, done, history, B, ans):#深さ優先探索（再帰）
  
  j = bs.bisect_left(B,A[i]) #Bへの挿入予定位置
  #print(i,A[i],j,B)
  
  #A[i]をhistoryの適当な位置に挿入
  if j < len(B):
    history[i] = (B[j], A[i], j) # 更新前の値、更新後の値、更新位置
    B[j] = A[i]
  else:
    history[i] = (-1, A[i], j) # 「追加する」 、追加する値、追加位置（最後）
    B.append(A[i])
  
  ans[i] = len(B) #答え書き込み
  done[i] = 1 #探索済み
  #print(i,B)
  
  for a in nbr[i]:
    if done[a] == 0: #探索前のみ
      dfs(a, nbr, A, prv, done, history, B, ans)
      prv[a] = i
      
  j = history[i][2]
  if history[i][0] >= 0:
    B[j] = history[i][0] #Bを現状復帰
  else:
    B.pop()
    
N = int(input()) 
A = list(map(int,input().split()))

nbr = [[] for _ in range(N)]

for _ in range(N-1):
  u,v = map(int,input().split())
  u -= 1
  v -= 1
  nbr[u].append(v)
  nbr[v].append(u)

#print(nbr)
  
prv = [-1 for _ in range(N)]
done = [0 for _ in range(N)] 
history = [0 for _ in range(N)]
B = []
ans = [0 for _ in range(N)]

dfs(0, nbr, A, prv, done, history, B, ans)

for i in range(N):
  print(ans[i])
