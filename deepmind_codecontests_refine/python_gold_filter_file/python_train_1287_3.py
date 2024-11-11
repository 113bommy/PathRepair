n=int(input())
a=[int(v) for v in input().split()]
if sum(a)%n==0:
    print(n)
else:
    print(n-1)