n = int(input())
arr = list(map(int, input().split()))
arr.sort()
if n % 2:
    print(arr[n//2])
else:
    print(arr[(n-1)//2])
