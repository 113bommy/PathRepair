n = int(input())
arr = list(map(int, input().split()))
for i in range(n):
    s = 1
    for j in range(n):
        if arr[j] > arr[i]:
            s += 1
    print(s, end=' ')