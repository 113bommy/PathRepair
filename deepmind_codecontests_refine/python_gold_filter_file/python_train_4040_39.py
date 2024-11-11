import heapq
N,M=map(int,input().split())
x={}
for i in range(M+1):
    x[i]=[]
for i in range(N):
    a,b=map(int,input().split())
    if a>M:
        continue
    x[a].append(-b)
y=[]
an=0
for i in range(M+1):
    for n in x[i]:
        heapq.heappush(y,n)
    try:
        an-=heapq.heappop(y)
    except:
        pass
print(an)