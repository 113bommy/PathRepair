N,Q=map(int,input().split())
S=input()
table=[]
for i in range(Q):
    t,d=input().split()
    table.append((t,d))
def f(x):
    u=x
    for t,d in table:
        if S[u]==t:
            if d=='L':
                u-=1
            else:
                u+=1
        if u==-1:
            return 0
        if u==N:
            return 1
    return 2
mi=0
ma=N-1
while ma-mi>1:
    mid=(ma+mi)//2
    if f(mid)==0:
        mi=mid
    else:
        ma=mid
left=mi
mi=0
ma=N-1
while ma-mi>1:
    mid=(ma+mi)//2
    if f(mid)==1:
        ma=mid
    else:
        mi=mid
right=ma
#print(left,right)
ans=(left+1)+(N-right)
num=N-ans
if left==0:
    if f(0)==2:
        num+=1
if right==N-1:
    if f(N-1)==2:
        num+=1
print(num)