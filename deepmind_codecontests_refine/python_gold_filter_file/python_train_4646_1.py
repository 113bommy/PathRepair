n = int(input())
lst = [(-1, -1, 0)]
for i in range(1, n + 1):
	li, ri = map(int,input().split())
	lst.append((li, ri, i))
lst.append((1000000001, 1000000001, n+1))
#print(lst)
lst.sort()
#print(lst)
for i in range(1, n + 1):
	tc = lst[i]
	tp = lst[i - 1]
	tn = lst[i + 1]
	if (tc[1] <= tp[1]) or (tc[0] >= tn[0] and tc[1] <= tn[1]) or (tp[1] + 1 >= tn[0] and tc[1] <= tn[1]):
		print(tc[2])
		break
else:
	print(-1)