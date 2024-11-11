n = int(input())
l = list(map(int, input().split()))
ans = []
for i in range(n):
    l[i] += 150000
ans.append([1, n, 150000])
for i in range(n):
    ans.append([2,i + 1, l[i] - i])
print(n + 1)
for i in range(n + 1):
    print(' '.join(map(str, ans[i])))
