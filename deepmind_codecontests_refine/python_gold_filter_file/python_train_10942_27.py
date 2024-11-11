tc=int(input())
for i in range(tc):
    s,a,b,c=map(int,input().split())
    d=s//c
    p=d//a
    p=p*b
    print(p+d)