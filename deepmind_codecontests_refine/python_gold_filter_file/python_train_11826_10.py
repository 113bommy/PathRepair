n = int(input())
arr = list(map(int, input().split()))
arr.sort()
coun = []
for k in range(n - 1):
    coun.append(arr[k+1]-arr[k])
zz = min(coun)
print(zz, coun.count(zz))