import math
for _ in range(int(input())):
    a,b = map(int,input().split())
    if ((a==1 and b<=1 and b>=0) or (a>3 and b>=0) or (a>1 and b<=3) ):
        print("Yes")
    else:
        print("no")