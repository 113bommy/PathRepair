n = int(input())
s = input()
b = 0
w = s.count('.')
ans = w
for i in range(n):
    if s[i] == '.':
        w -= 1
    else:
        b += 1
    ans = min(ans, w + b)
print(ans)