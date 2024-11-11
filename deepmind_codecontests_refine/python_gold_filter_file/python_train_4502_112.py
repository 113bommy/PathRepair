import math
t=int(input())
for i in range(t):
    n=int(input())
    if n==1 or n==2:
        print(0)
    elif n%2!=0:
        x=math.ceil(n/2)
        print(n-x)
    elif n%2==0:
        print(int(n/2-1))