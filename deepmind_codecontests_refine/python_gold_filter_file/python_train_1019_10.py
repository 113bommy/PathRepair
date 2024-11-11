n = int(input())
s = input()
bs = 0
ws = s.count('.')
ans = ws
for c in s:
    if c == '.':
        ws -= 1
    else:
        bs += 1
    now = ws + bs
    if ans > now:
        ans = now
print(ans)
