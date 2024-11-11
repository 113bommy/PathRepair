n = int(input())
a = [int(i) for i in input().split()]
a.sort()

if n%2 == 0:
    print(a[(n-1)//2])
else:
    print(a[n//2])
