t = int(input())
for i in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    if(arr[0]+arr[1]<=arr[-1]):
        print(1, 2, n)
    else:
        print(-1)