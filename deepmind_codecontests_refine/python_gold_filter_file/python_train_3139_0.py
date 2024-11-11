import itertools
h, n = map(int, input().split(' '))
arr = list(map(int, input().split(' ')))
arr = list(map(lambda x: -x, arr))
s = sum(arr)

# starting case 
tmp = h
ans = 0
for i in arr:
    if tmp <= 0:
        print(ans)
        exit(0)
    tmp -= i
    ans += 1

if tmp <= 0:
    print(ans)
    exit(0)

ans = 0

# impossible case
if s <= 0:
    print(-1)
    exit(0)

running_max = 0
curr = 0
for num in arr:
    curr += num
    if curr > running_max:
        running_max = curr

iterations = h // s
mod = h % s
# how many iters to back up
# print(f'running_max: {running_max}')
# print(f's: {s}')

to_backup = running_max // s
# print(to_backup)

ans = ((iterations - to_backup) * n)

mod  += to_backup * s  

for p in itertools.cycle(arr):
    if mod <= 0:
        break
    mod -= p
    ans += 1

print(ans)
