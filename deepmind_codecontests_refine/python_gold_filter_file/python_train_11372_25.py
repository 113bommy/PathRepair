def ii(): return int(input())
def mi(): return map(int, input().split())
def ai(): return list(map(int, input().split()))

u,v = mi()
if u>v or u&1 != v&1:
	print(-1)
elif u==0 and v == 0:
	print(0)
else:
	x = (v-u)//2
	if x:
		if u&x!=0:
			print(3)
			print(u,x,x)
		else:
			print(2)
			print(u+x,x)
	else:
		print(1)
		print(u)