from collections import deque
p, k = map(int, input().split())
nums = list(map(int, input().split()))
state = deque(maxlen=k)
l = 0
for num in nums:
	if num not in state:
		state.appendleft(num)
		if l < k:
			l += 1
ans = ''
for _ in range(l):
	ans += str(state.popleft())
	ans += ' '
laa = l if l < k else k
print(laa)
print(ans[:-1]) 