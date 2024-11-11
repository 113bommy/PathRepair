import collections

n = int(input())

nums = list(map(int,input().split()))

d = collections.defaultdict(int)

for i in nums:
	d[i] += 1

k = sorted(d.keys())

if len(k)==1:
	print(d[k[0]])
	exit()


t = d[k[0]]
s = 0

for i in range(1,len(k)):
	in_boxes = min(d[k[i]],t)
	t = t + d[k[i]] - in_boxes
	s += in_boxes
print(n-s)
