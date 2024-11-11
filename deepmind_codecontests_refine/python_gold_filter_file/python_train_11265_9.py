n = int(input()) + 1
a = [10**18] + list(map(int, input().split())) + [-1, -1]
stack = []
length = 1

for i, x, y in zip(range(2, n+1), a[1:], a[2:]):
    if x >= y:
        stack.append((length, i))
        length = 1
    else:
        length += 1


stack.append((0, n))
ans = 0

for (x, i), (y, _) in zip(stack, stack[1:]):
    if a[i-1] < a[i+1] or a[i-2] < a[i]:
        ans = max(ans, x + y - 1)
    else:
        ans = max(ans, x)

print(ans)
