a,b=map(int,input().split())
y=[]
i=b-a
w=a-1
r=0
for i in range(a,b+1):
    w+=1
    q=list(str(w))
    for j in range(len(q)):
        if q[j] not in y:
            y.append(q[j])
    if len(y)==len(q):
        r=1
        break
    else:
        y=[]
if r==1:        
    print(w)
else:
    print(-1)
