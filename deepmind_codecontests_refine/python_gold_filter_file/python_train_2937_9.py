r,c=map(int,input().split())
a=[]
for i in range(r+1):
    a.append([0]*(c+1))
if c==r==1:
    print(0)
elif c==1:
    for i in range(1,r+1):
        print(i+1)
else:
    for i in range(1,r+1):
        for j in range(1,c+1):
            a[i][j]=i * (j + r)
    for i in range(1,r+1):
        for j in range(1,c+1):
            print(a[i][j],end=" ")
        print();
   
