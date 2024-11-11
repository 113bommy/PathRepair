n, k = map(int, input().split())
t = list(map(int, input().split()))
t = sorted(t)
if n == k and k == 2:
    print(abs(t[0] - t[1]))
    exit(0)
if t[0] == t[-1]:
    print(0)
    exit(0)
t_sum_r = [t[-1]]
for x in range(0, n-k+1):
    if t[x] == t[x+k-1]:
        print(0)
        exit(0)
for x in range(2, n+1):
    t_sum_r.append(t[-x] + t_sum_r[x-2])
t_sum_l = 0
sum_l = t[0]
wyn = 10**16
curr_wyn_l = 10**16
curr_wyn_r = 10**16
curr_wyn_lr = 10**16
curr_min = 10**16
for x in range(1, n-1):
    cost_l = (x) * (t[x]-1) - sum_l + 1
    cost_r = t_sum_r[-x - 2] - ((n - x - 1) * (t[x] + 1)) + 1
    el_l = x
    el_r = n - x - 1
    sum_l += t[x]
    if el_l + 1 >= k:
        curr_wyn_l = cost_l + (k - 2)
    if el_r + 1 >= k:
        curr_wyn_r = cost_r + (k - 2)
    curr_wyn_lr = cost_l + cost_r + (k - 3)
    curr_min = min(curr_wyn_lr, curr_wyn_l, curr_wyn_r)
    if curr_min <= wyn:
        wyn = curr_min
print(wyn)