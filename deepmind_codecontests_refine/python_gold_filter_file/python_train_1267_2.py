n, x, y = list(map(int, input().split()))
arr = list(map(int, input().split()))
for i in range(n):
    if i < x and min(arr[:i + y + 1]) == arr[i] or i >= x and min(arr[i - x:i + y + 1]) == arr[i]:
        print(i + 1)
        break