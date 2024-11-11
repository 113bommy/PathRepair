n=int(input())
L=[int(i) for i in input().split()]
if sum(L)%n==0:
    print(n)
else:
    print(n-1)