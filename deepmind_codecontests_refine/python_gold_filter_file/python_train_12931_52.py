n,m=map(int,input().split())
a=list(map(str,input().split()))
b=list(map(str,input().split()))
for i in range(int(input())):
    k=int(input())
    x=k%len(a)
    y=k%len(b)
    print(a[x-1]+b[y-1])
