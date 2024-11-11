n = int(input())
ans = 0
t = 7
w = n
temp = 1
while (t>0):
	temp *= w
	w-=1
	t-=1
ans = temp//5040
t = 6
w = n
temp = 1
while (t>0):
	temp *= w
	w-=1
	t-=1
ans += temp//720
t = 5
w = n
temp = 1
while (t>0):
	temp *= w
	w-=1
	t-=1
ans += temp//120
print (ans)
