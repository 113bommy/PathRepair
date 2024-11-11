n=int(input())
a=list(map(int,input().split()))
a.sort()
try:
    while a[0]==a[1]:
        a.pop(0)
        n-=1
    while a[n-1]==a[n-2]:
        a.pop(n-2)
        n-=1
    print(n-2)
except:
    print(0)
