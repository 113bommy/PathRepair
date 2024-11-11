def letters():
    return (chr(i) for i in range(ord('a'), ord('z') + 1))


s = input()

ls = {lt: 0 for lt in letters()}

for lt in s:
    ls[lt] += 1

s = [ch for ch in reversed(s)]
stack = []
res = []

for curr in letters():
    while stack and stack[-1] <= curr:
        res.append(stack.pop(-1))
    while ls[curr] > 0:
        if s[-1] != curr:
            c = s.pop(-1)
            ls[c] -= 1
            stack.append(c)
        else:
            ls[curr] -= 1
            res.append(s.pop(-1))
res += reversed(stack)
print(''.join(res))
