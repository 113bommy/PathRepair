from heapq import heappop, heappush, heapify

n = int(input())
al = list(map(int, input().split()))

ll = al[0:n]
cl = al[n:2*n]
rl = al[2*n:3*n]
rl = list(map(lambda x: -x, rl))


heapify(ll)
heapify(rl)

ll_vals = []
ll_vals.append(sum(ll))
c_sum = sum(ll)
c_max = c_sum
for i in range(n):
    poped = heappop(ll)
    c_sum -= poped
    heappush(ll,cl[i])
    c_sum += cl[i]
    c_max = max(c_max, c_sum)
    ll_vals.append(c_max)


rl_vals = []
rl_vals.append(-sum(rl))
c_sum = -sum(rl)
c_min = c_sum
for i in range(n):
    poped = -heappop(rl)
    c_sum -= poped
    heappush(rl,-cl[n-1-i])
    c_sum += cl[n-1-i]
    c_min = min(c_min, c_sum)
    rl_vals.append(c_min)


ans = -1*(10**18)
for i in range(n+1):
    v = ll_vals[i] - rl_vals[n-i]
    ans = max(ans,v)

print(ans)