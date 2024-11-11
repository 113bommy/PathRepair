n = int(input())
arr = list(map(int, input().split()))
arr.sort(reverse = True)

ans = arr[0]
for i in range(1,len(arr)):
    arr[i] = max(0,min(arr[i-1]-1,arr[i]))
    ans += arr[i]

print(ans)