n, k = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
a = sorted(a, reverse = True)
eat = [k] * n
i = 1
current = 0
l = len(a)
ans = 1
while (current < l) and (i < l):
	if a[i] < a[current] <= a[i] + eat[current]:
		eat[current] = k + (a[current] - a[i])
		i += 1
	else:
		current = i
		i += 1
		ans += 1
			

print(ans)
#print(lines)
#f = [True] * n
#ans = 0
#for i in range(n):
#	if f[i]:
#		ans += 1
#		q = [i]
#		head = 0
#		while head != len(q):
#			for j in lines[q[head]]:
#				if f[j]:
#					f[j] = False
#					q.append(j)
#			head += 1
#		#print(q)
#print(ans)
