n,k=map(int,input().split())
l=[int(n) for n in input().split(" ")]
temp=sorted(l)
a=0
ans=[]
flag=0
for i in range(n):
    if temp[i]!=a:
        ct=1
        a=temp[i]
    else:
        ct+=1
    if ct>k:
        print("NO")
        flag=1
        break
a=0
for i in range(n):
    if temp[i]!=a:
        ans.append(1)
        a=temp[i]
    else:
        ans.append(ans[i-1]+1)
a=[]
for i in range(n):
    index=temp.index(l[i])
    a.append(ans[index])
    temp[index]=-temp[index]
b=1
q=max(a)
w=[]
for i in range(n):
    w.append(0)
for i in range(n):
    w[a[i]-1]+=1
for i in range(k,q,-1):
    a[a.index(b)]=i
    w[b-1]-=1
    if w[b-1]==1:
        b+=1
if flag==0:
    print("YES")
    for i in a:
        print(i,end=' ')