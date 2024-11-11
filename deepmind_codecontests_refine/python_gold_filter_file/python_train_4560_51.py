n, k = map(int, input().split())
a = list(map(int, input().split()))
f = list(map(int, input().split()))
a.sort()
f.sort(reverse=True)

right = 0
left = a[-1]*f[0]

while right!=left:
    mid = (right+left)//2
    syu = 0
    
    for i in range(n):
        if a[i]*f[i]>mid:
            syu += a[i] - mid//f[i]
    
    if syu <= k:
        left = mid
    else:
        right = mid + 1
        
print(right)