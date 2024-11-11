n = int(input())
arr = []
for i in range(n):
    l, r = map(int, input().split())
    arr.append((l, -r, i))

ans = '-1 -1'

a = sorted(arr)

for i in range(len(a)):
    a[i] = (a[i][0], -a[i][1], a[i][2])

for i in range(len(a)-1):
    if a[i][0] <= a[i+1][0] and a[i][1] >= a[i+1][1]:
        ans = str(a[i+1][2] + 1) + ' ' + str(a[i][2] + 1) 

print(ans)
