n = int(input())
l = [int(i) for i in input().split()]
l.sort()
k = n*2-1
ans = 'YES'

for i in range(n):
	if l[k] == l[i]:
		ans = 'NO'
		break
	k = k-1
print(ans)
