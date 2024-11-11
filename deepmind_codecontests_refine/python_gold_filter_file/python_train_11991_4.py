s = input().rstrip()
t = input().rstrip()

left = []
idx = 0
for i, item in enumerate(s):
    if item == t[idx]:
        left.append(i)
        idx += 1
    if idx == len(t):
        break
right = []
idx = len(t) - 1
for i, item in enumerate(s[::-1]):
    if item == t[idx]:
        right.append(len(s) - i - 1)
        idx -= 1
    if idx == -1:
        break
right.reverse()
ans = max(right[0], len(s) - right[-1] - 1) 
ans = max(ans, left[0], len(s) - left[-1] - 1) 
for l, r in zip(left, right[1:]):
    ans = max(ans, r - l - 1)

print(ans)