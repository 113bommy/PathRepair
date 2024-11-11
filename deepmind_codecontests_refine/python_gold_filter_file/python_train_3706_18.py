a,b=list(map(int,input().split()))
for i in range(a+1,55):
    for j in range(2,i):
        c=True
        if i%j==0:
            c=False
            break
        if i%j!=0:
            c=True
    if c==True :
        break
if i==b:
    print("YES")
else:
    print("NO")
