n, k = [int(x) for x in input().split()]
ain = input()
 
last = 'Z'
cnt = 0
a = [0] * 26
for x in ain:
	if x is last:
		cnt += 1
	else:
		cnt = 1
	if cnt == k:
		a[ord(x) - ord('a')] += 1
		cnt = 0
	last = x
 

print(max(a))