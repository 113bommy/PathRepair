n = int(input())
ar = list(map(int, input().split()))
ar.sort()
if n % 2 == 0:
    print(ar[int(n / 2 - 1)])
else:
    print(ar[int((n - 1) / 2)])
