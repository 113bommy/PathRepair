n = int(input())
arr = list(map(int,input().split()))
x = sum(arr)
if x%n==0:
    print(n)
else:
    print(n-1)
