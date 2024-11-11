n, c = map(int, input().split())
l = [0]+list(map(int, input().split()))
p=0

for i in range(n):
	if l[i+1]-l[i]<=c:
		p+=1
	else:
		p=1
print(p)