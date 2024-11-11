n = int(input())
arr = list(map(int,input().split()))
s = sum(arr)
if s%n:
    print(n-1)
else:
    print(n)