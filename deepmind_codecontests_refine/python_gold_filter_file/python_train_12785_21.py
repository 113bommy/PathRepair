N = int(input())

l= []
for i in range(N):

	a,b = map(int, input().split())
	l.append([a,b,a+b])

l.sort(key=lambda x:x[2])
l.reverse()


ans = 0
for i in range(N):
	if i%2 == 0:
		ans+= l[i][0]
	else:
		ans-= l[i][1]

print(ans)
