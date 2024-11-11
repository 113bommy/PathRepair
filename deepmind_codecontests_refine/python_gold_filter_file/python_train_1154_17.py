n, m = map(int, input().split())
a = [int(x) for x in input().split()]
temp = 0
ans = []
for x in a:
    temp += x
    ans.append(temp//m)
    if temp >= m:
        temp = temp%m
for x in ans:
    print(x, end=" ")