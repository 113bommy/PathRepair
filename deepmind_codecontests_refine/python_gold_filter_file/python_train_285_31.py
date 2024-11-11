from heapq import heapify, heappop, heappush
Ncase = int(input())
for case in range(Ncase):
  N = int(input())
  ans = 0
  Left = [];Right = []
  for i in range(N):
    K,L,R = map(int,input().split())
    if L > R:
      Left.append((K-1,L-R))
      ans += R
    elif R > L:
      if K != N: #K=Nの時はどこにおいても左と判定される。
        Right.append((N-1-K,R-L))
      ans += L
    else:
      ans += L
  Left.sort(reverse=True);Right.sort(reverse=True) #Kの小さい順、左にいたときのプラス分が大きい順に並んだ
  #print(Left,Right)
  now = 0
  PQ = []
  for loc in reversed(range(N)):
    #print(now,Left[now][0],loc)
    while now < len(Left) and Left[now][0] == loc:
      heappush(PQ,-Left[now][1])
      now += 1
      if now >= len(Left):
        break
    if PQ:
      plus = -heappop(PQ)
      ans += plus
  
  now = 0
  PQ = []
  for loc in reversed(range(N)):
    while now < len(Right) and Right[now][0] == loc:
      heappush(PQ,-Right[now][1])
      now += 1
      if now >= len(Right):
        break
    if PQ:
      plus = -heappop(PQ)
      ans += plus
  print(ans)