n,m=map(int,input().split())
a=input().split()
b=input().split()
q=int(input())
for x in range(q):
    c=int(input())
    c-=1
    print(a[c%n]+b[c%m])
