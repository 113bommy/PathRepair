n=int(input())
for _ in range(n):
    a,b=map(int,input().split())
    if (a==b):
        print(0)
    elif (a>b and (a-b)%2==0) or (a<b and (b-a)%2==1):
        print(1)
    else:
        print(2)
