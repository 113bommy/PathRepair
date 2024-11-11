x=int(input())
y=list(map(int,input().split(" ")))
y=sorted(y)
t=True
c=0
m=0
q=y[0]
a=[y[0]]
b=[]
for i in range(1,len(y)):
    if y[i]==q:
        c+=1
        t=not(t)
    else:
        c=0
    q=y[i]
    m=max(m,c) 
    if t:
        a.append(y[i])
    else:
        b.append(y[i])
if m>1:
    print("NO")
else:
    print("YES")
    print(len(a))
    print(" ".join(list(map(str,a))))
    print(len(b))
    print(" ".join(list(map(str,reversed(b)))))