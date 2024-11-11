n=int(input())
for i in range(n):
    a,b,c = map(int,input().split())
    if c<a:
        print(c)
    else:
        print((b//c+1)*c)