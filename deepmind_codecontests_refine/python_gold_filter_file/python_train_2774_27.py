# python3
# utf-8

n, k = (int(x) for x in input().split())
type___capacity = [int(x) for x in input().split()]
ans = -1
nr = 0
left = 2 * n
for typ in range(k):
    curr_cap = type___capacity[typ]
    curr_left = n % curr_cap
    if curr_left == 0:
        ans = typ + 1
        nr = n // curr_cap
        break
    elif curr_left < left:
        ans = typ + 1
        left = curr_left
        nr = n // curr_cap
print(ans, nr)
