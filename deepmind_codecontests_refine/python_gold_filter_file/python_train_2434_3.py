# from debug import debug
import sys

n, m = map(int, sys.stdin.readline().split())
lis = sorted(list(map(int, sys.stdin.readline().split())), reverse=True)
s = [0]*n
e = [0]*n
for i in range(m):
	a, b = map(int, sys.stdin.readline().split())
	s[a-1] += 1
	e[b-1] += 1
store = []
start = 0
end = 0
d = 0
for i in range(n):
	if s[i] and not e[i]:
		store.append((start-end, d))
		start+=s[i]
		d = 1
	elif not s[i] and e[i]:
		d+=1
		store.append((start-end, d))
		end+=e[i]
		d = 0
	elif s[i] and e[i]:
		store.append((start-end, d))
		store.append((s[i]+start-end, 1))
		start+=s[i]
		end += e[i]
		d=0
	else:
		d+=1
l = 0
ans = 0
store.sort(reverse=True)
cumm = [0]*n
cumm[0] = lis[0]
for i in range(1,n):
	cumm[i] = cumm[i-1]+lis[i]

for i in range(len(store)-1):
	b,c = store[i]
	if n>(l+c-1)>=l:
		ans += (cumm[l+c-1]-cumm[l]+lis[l])*b
	l += c
print(ans)
