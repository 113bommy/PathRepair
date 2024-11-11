n = int(input())


arr = []

r = lambda : list(map(int, input().split()))

for i in range(n):
    arr.append(r())


ans = [[] for i in range(n)]
for i in range(n):
    ans[i] = [arr[i][0] , arr[i][0] + arr[i][1]]

f = False
for i in ans:
    if i[::-1] in ans:
        f = True
        break


print("YES" if f else "NO")
