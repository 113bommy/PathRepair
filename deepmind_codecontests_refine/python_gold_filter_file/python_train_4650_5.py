import heapq 
n,k,k1=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=[-1*abs(a[i]-b[i]) for i in range(n)]
#print(c)
c.sort(reverse=True)
heapq.heapify(c)
k+=k1
while(k>0):
    e=heapq.heappop(c)
    #print(e)
    if e==0:
        heapq.heappush(c,e)
        break 
    heapq.heappush(c,e+1)
    k-=1
s=0
#print(c)
for j in range(len(c)):
    s+=c[j]*c[j]
    c[j]*=-1
ce=k%2
ad=ce*2*min(c)+ce
print(s+ad)
    