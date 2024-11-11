n,m=map(int,input().split())
a=input().split()
b=input().split()
q=int(input())
for i in range(q):
    j=int(input())-1
    print(a[j%n]+b[j%m])
