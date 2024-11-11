N,M=map(int,input().split())

flag=list(range(N))
def takeflag(p):
    stock=[]
    while flag[flag[p]]!=flag[p]:
        stock.append(p)
        p=flag[p]
    p=flag[p]
    for i in stock:
        flag[i]=p
    return p

for i in range(M):
    x,y,z = map(int,input().split())
    x,y=x-1,y-1
    x,y = map(takeflag,(x,y))
    x,y = min(x,y),max(x,y)
    flag[x]=y

st=set()
for i in range(N):
    st.add(takeflag(i))

print(len(st))