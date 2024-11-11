n, k = map(int, input().split())
s = input()

r = len(s) - 1

a = [0] * (len(s) + 1)

while r >= 0:
    a[r] = a[r + 1] + (s[r] == ')')
    r -= 1

cnt = 0
need = k // 2

for i in range(len(s)):
    if s[i] == '(' and a[i] >= cnt + 1 and need > 0:
        cnt += 1
        need -= 1
        print('(', end='')
    elif s[i] == ')' and cnt > 0:
        cnt -= 1
        print(')', end='')

print()