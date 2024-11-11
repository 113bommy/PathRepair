

N=int(input())

friendlist=[0 for i in range(N+2)]

"""
for i in range(N):
    a,b=[int(j) for j in input().split(" ")]
    for k in range(a,min(b+1,N+2)):
        friendlist[k]+=1
"""


ab=[[int(i) for i in input().split(" ")] for j in range(N)]
a=[ab[i][0] for i in range(N)]
b=[ab[i][1] for i in range(N)]

a.sort()
b.sort()



for i in range(1,N):
    for j in range(a[i-1],min(a[i],N+2)):
        friendlist[j]+=i
for i in range(a[N-1],N+2):
    friendlist[i]+=N

for i in range(1,N):
    for j in range(b[i-1]+1,min(b[i]+1,N+2)):
        friendlist[j]-=i
for i in range(b[N-1]+1,N+2):
    friendlist[i]-=N
        


#"""

k=N+1
i=0
while k>=0:
    if friendlist[k]>=k-1:
        i=k-1
        break
    k-=1

print(i)
    
        