import math
t=int(input())
while t:
    n,k = list(map(int,input().split()))

    d=math.sqrt(n)

    if k<=math.floor(d):

        if n%2==0 and k%2==0:
            print("YES")
        elif n%2==1 and k%2==1:
            print("YES")
        else:
            print("NO")
    else:
        print("NO")
    t=t-1