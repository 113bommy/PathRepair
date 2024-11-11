l=[]
for _ in range(int(input())):
    n,m=map(int,input().split())
    a=n-m

    if a>0:

        a=1 if a%2==0 else 2

    elif(a<0):

        a=1 if a%2!=0 else 2
    l.append(a)
[print(i) for i in l]