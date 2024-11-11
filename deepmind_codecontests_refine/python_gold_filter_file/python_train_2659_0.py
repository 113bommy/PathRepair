n,h = map(int,input().split())
arr = list(map(int,input().split()))
width = 0
for i in range(n):
    if arr[i] <= h:
        width += 1
    else:
        width += 2
print(width)