n = int(input())
arr = [int(i) for i in input().split()]
res = 0
i = 2

if (n > 2):
    while (i < n):
        temp = 2

        while (i < n and arr[i] == arr[i-1] + arr[i-2]):
            temp += 1
            i += 1
        
        i += 1
        res = max(res, temp)
else:
    res = n

print(res)