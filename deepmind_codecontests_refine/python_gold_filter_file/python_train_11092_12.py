n = int(input())
s = input()
a = list(map(int,input().split()))

if "L" not in s:
    print(-1)
    exit(0)
if "R" not in s:
    print(-1)
    exit(0)

ans = []
flag = 0
for i in range(n):
    if s[i] == "R":
        right = a[i]
        flag = 1
    elif flag and s[i] == "L":
        left = a[i]
        flag = 0
        ans.append([right,left])

min = 10**10
if ans:
    for i in ans:
        val = abs(i[0]-i[1])
        if val<min:
            min = val
    print(min//2)
else:
    print(-1)