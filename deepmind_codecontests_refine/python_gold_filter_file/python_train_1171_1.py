import sys

input=sys.stdin.readline

n,h,m,k=map(int,input().split())
tram=[]
dic={}
for i in range(n):
    H,M=map(int,input().split())
    r=M%(m//2)
    tram.append(r)
    if r not in dic:
        dic[r]=0
    dic[r]+=1

S=[i for i in dic]
for i in S:
    dic[i+m//2]=0
    dic[i+m//2]=dic[i]

data=[(i,dic[i]) for i in dic]
data.sort()
#print(data)

#imos=[data[i][1] for i in range(len(data))]
#for i in range(len(imos)-1):
    #imos[i]+=imos[i-1]

if k==1:
    print(0,0)
    print(*[])
    exit()

k-=1
query=[]
for i in dic:
    query.append((i+1,-dic[i]))
    query.append((i-k+1,dic[i]))

query.sort(reverse=True)
#print(query)
S=0
while query and query[-1][0]<=0:
    t,val=query.pop()
    S+=val
ans=S
res=0
while query and query[-1][0]<m//2:
    time,val=query.pop()
    S+=val
    while query and query[-1][0]==time:
        time,val=query.pop()
        S+=val
    if ans>S:
        ans=S
        res=time

#print(res)
Ans=ans
print(Ans,(res+k)%(m//2))
ans=[]
for i in range(n):
    L=res
    R=res+k-1
    if R>=tram[i]>=L or R>=tram[i]+(m//2)>=L:
        ans.append(i+1)
if len(ans)!=Ans:
    print("WA")
print(*ans)
