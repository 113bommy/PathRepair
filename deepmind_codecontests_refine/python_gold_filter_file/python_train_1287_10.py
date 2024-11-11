n=int(input())
a=[int(a) for a in input().split()]
if sum(a)%n==0:
    print (n)
else:
    print (n-1)
