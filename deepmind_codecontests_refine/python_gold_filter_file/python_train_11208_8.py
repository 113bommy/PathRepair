from sys import stdin, stdout

n = stdin.readline().rstrip()
str = stdin.readline().rstrip()

ans = 0
x_streak = 0
for c in str:
    if c == 'x':
        x_streak += 1
    else:
        if x_streak > 2:
            ans += x_streak-2
        x_streak = 0

if x_streak > 2:
    ans += x_streak-2

print(ans)