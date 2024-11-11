import sys
reader = (s.rstrip() for s in sys.stdin)
input = reader.__next__

n = int(input())
a = list(map(int, input().split()))

left = [0]
right = [0]
for ai in a:
    left.append(left[-1]|ai)
for ai in reversed(a):
    right.append(right[-1]|ai)

maximum = 0
max_ind = 0
for i, ai in enumerate(a):
    mask = left[i]|right[n-1-i]
    tmp = (ai|mask) - mask
    if tmp > maximum:
        maximum = tmp
        max_ind = i
ans = [a[max_ind]]
for i in range(n):
    if i != max_ind:
        ans.append(a[i])
print(*ans)
