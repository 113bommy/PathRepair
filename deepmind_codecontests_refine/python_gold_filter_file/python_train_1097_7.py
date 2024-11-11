n=int(input())
a=[]
b=[]
sumx=0
sumy=0
sumz=0
for i in range(n):
    a=list(map(int,input().split()))
    b.append(a)

    sumx=sumx+b[i][0]
    sumy=sumy+b[i][1]
    sumz=sumz+b[i][2]
if sumx==0 and sumy==0 and sumz==0:
    print("YES")
else:
    print("NO")