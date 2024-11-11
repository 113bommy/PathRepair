n, m, r = map(int, input().split())

a = (int(i) for i in input().split())
b = max(int(i) for i in input().split())
ans = r
for cost in a:
    ans = max(ans, r // cost * b + r % cost)
print(ans)
