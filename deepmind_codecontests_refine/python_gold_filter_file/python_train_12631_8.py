n,m=map(int,input().split())
b=set()
for i in range(n):
    a=set(input())
    if len(a)>1 or a==b:
        print("NO")
        exit(0)
    b=a
print("YES")