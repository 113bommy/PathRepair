import heapq
n,m= map(int,input().split())
feeindays = [[] for _ in range(m)]
for i in range(n):
    a,b= map(int,input().split())
    if a<=m:feeindays[a-1]+=[b]
q=[]
heapq.heapify(q)
pay=0
for l in feeindays:
    for c in l:heapq.heappush(q,-c)
    if len(q)!=0:pay+=-1 * heapq.heappop(q)
print(pay)