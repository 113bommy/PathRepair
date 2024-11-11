maxi=-10**99 
n=int(input())
import heapq 
l=[int(i) for i in input().split()]
k=n
sm=sum(l[0:n])
z1=[0]*(n+1)
z2=[0]*(n+1)
h=[]
z1[0]=sm 
j=1 
heapq.heapify(h)
for i in range(n):
    heapq.heappush(h,l[i])
for i in range(n,2*n):
    p=l[i]
    if p>h[0]: 
        sm+=p 
        sm-=h[0]
        heapq.heappop(h)
        heapq.heappush(h,p)
    else:
        pass 
    z1[j]=sm 
    j+=1 
sm=sum(l[2*n:3*n])
h=[]
heapq.heapify(h)
sm=0 
for i in range(2*n,3*n):
    heapq.heappush(h,-l[i])
    sm+=(l[i])
j=n 
z2[j]=sm  
j-=1 
#print(h[0])
#print(sm)
for i in range(2*n-1,n-1,-1): 
    p=-l[i]
    if p>h[0]:
        #print('jif')
        sm=sm+h[0]-p
        heapq.heappop(h)
        heapq.heappush(h,p)
        
    else:
        pass 
    z2[j]=sm 
    j-=1 
maxi=-(10**99)
#print(z1)
#print(z2)
for i in range(n+1):
    maxi=max(maxi,z1[i]-z2[i])
print(maxi)