n, l = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
a.sort()
begDistance = float(a[0] - 0)
endDistance = float(l - a[-1])
maxDistanceBetweenLanterns = 0
for i in range(len(a) - 1):
    if (a[i+1] - a[i])/2 > maxDistanceBetweenLanterns:
        maxDistanceBetweenLanterns = (a[i+1] - a[i])/2
ans = max(begDistance, endDistance, maxDistanceBetweenLanterns)
print(ans)