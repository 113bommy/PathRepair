n = int(input())
st = [input().split() for _ in range(n)]
x = input()
flag = False
ans = 0
for s, t in st:
    if flag:
        ans += int(t)
    if s == x:
        flag = True
print(ans)