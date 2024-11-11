n=int(input())
ans=[0]*n

for x in range(1,100):
	for y in range(1,100):
		for z in range(1,100):
			v=x**2 + y**2 + z**2 + x*y +y*z +x*z
			if v>n:
				break
			ans[v-1]+=1

print(*ans)