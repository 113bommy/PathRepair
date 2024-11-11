a=[]
for i in range(1,33):
	a.append((i*(i+1))//2)
t=int(input())
print('YES' if t in a else 'NO')