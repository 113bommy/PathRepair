n=int(input()) 
a=list(map(int,input().split()))
for i in range(1,n):
    if a[i-1]>a[i]:
        print(n-i if sorted(a)==a[i:]+a[:i] else -1)
        break
else:
    print(0)