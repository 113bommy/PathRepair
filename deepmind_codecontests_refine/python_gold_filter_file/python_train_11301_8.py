l, r, l1, r1, k = map(int, input().split())
arr = [l, l1]
arr1 = [r, r1]
arr.sort()
arr1.sort()
left = arr[1]
right = arr1[0]
ans = right - left + 1
if left <= k <= right:
    ans -= 1
print(max(ans,0))
