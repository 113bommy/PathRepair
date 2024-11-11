n = int(input())
ans = 0
op = False
for s in input().split():
    if s == '1' and op:
        ans += 1
    elif s == '0' and op:
        op = False
        ans += 1
    elif s == '1' and not op:
        op = True
        ans += 1
print(ans - (not op and ans > 0))
