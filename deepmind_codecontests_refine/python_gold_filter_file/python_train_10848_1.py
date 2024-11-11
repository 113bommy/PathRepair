from sys import stdin

input = stdin.readline

a, b, c, d = map(int, input().split())

if abs(a + c - b - d) > 1:
    print("NO")
    exit(0)

ans = [-1]

for i in range(a + c):
    if i < c:
        ans.append(2)
        ans.append(-1)
    else:
        ans.append(0)
        ans.append(-1)

def check(lst):
    pre = -1
    for i in lst:
        if pre != -1 and abs(pre - i) != 1:
            return False
        pre = i
    return True


if a + c <= b + d:
    i = 0
    while i // 2 < b + d:
        if i // 2 < d:
            ans[i] = 3
        else:
            ans[i] = 1
        i += 2
    if check(ans[:a + b + c + d]):
        print("YES")
        print(*ans[:a + b + c + d])
    else:
        print("NO")
else:
    i = 2
    while i // 2 - 1 < b + d:
        if i // 2 - 1 < d:
            ans[i] = 3
        else:
            ans[i] = 1
        i += 2
    if check(ans[1:a + b + c + d + 1]):
        print("YES")
        print(*ans[1:a + b + c + d + 1])
    else:
        print("NO")
