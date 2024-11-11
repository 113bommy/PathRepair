import heapq
N = int(input())
node = [[] for _ in range(N)]
for _ in range(N-1):
  a,b,c = map(int,input().split())
  node[a-1].append([c,b-1])
  node[b-1].append([c,a-1])
Q,K = map(int,input().split())

flag = [True]*N
ques = [[0,K-1]]
D = [0]*N
while ques:
  d1,l1 = heapq.heappop(ques)
  if flag[l1]:
    flag[l1]=False
    D[l1] = d1
    for d2,l2 in node[l1]:
      if flag[l2]:
        heapq.heappush(ques,[d1+d2,l2])
for _ in range(Q):
  x,y = map(int,input().split())
  print(D[x-1]+D[y-1])
        
