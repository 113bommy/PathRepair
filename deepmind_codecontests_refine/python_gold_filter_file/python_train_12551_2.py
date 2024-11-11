
import sys
#sys.stdin=open("data.txt")
#sys.stdout=open("data.txt","w")
input=sys.stdin.readline

n,k=map(int,input().split())
g=[[] for _ in range(n+1)]
vis=[0]*(n+1)

for _ in range(n-1):
    u,v=map(int,input().split())
    g[u].append(v)
    g[v].append(u)

def getans(u,k):
    vis[u]=1
    # first k -> need k
    # then cover exact
    # last k -> covers k above
    totalv=[0]*(2*k+1)
    totalv[k-1]=1
    carry=1             # total when this node is black
    for v in g[u]:
        if vis[v]: continue
        getv=getans(v,k)
        carry=(carry*sum(getv))%1000000007
        out2=[0]*(2*k+1)
        #print("before",totalv)
        for i in range(1,2*k+1):
            for j in range(2*k+1):
                if j+i>=2*k:
                    out2[max(i-1,j)]+=getv[i]*totalv[j]
                else:
                    out2[min(i-1,j)]+=getv[i]*totalv[j]
        for i in range(2*k+1):
            totalv[i]=out2[i]%1000000007
        #print("after ",totalv,carry)
    totalv[2*k]+=carry
    #print(u,totalv)
    return totalv

if k==0: print(1)
else:
    temp=getans(1,k)
    print(sum(temp[k:])%1000000007)