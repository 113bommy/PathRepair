import math
for i in range(int(input())):
    f=1
    n=int(input())
    a=list(map(int,input().split()))
    for j in a:
        if math.sqrt(j)%1!=0:
            f=0
            break
    if f==1:
        print("NO")
    else:
        print("YES")
