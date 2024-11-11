n, q = map(int, input().split(' '))
nums = [int(x) for x in input().split(' ')]
changes = [0]*(n+1)
for i in range(q):
    l, r = map(int, input().split(' '))
    changes[l-1] += 1
    changes[r] -= 1

mlts = [0]*n
cur_layers = 0
for i in range(n):
    cur_layers += changes[i]
    mlts[i] = cur_layers
mlts.sort()
nums.sort()
res = 0
for i in range(n):
    res += mlts[i]*nums[i]
print(res)