n = int(input()) 
a = [] 
a = input().split()
a = [int(i) for i in a] 
b = [] 
ans = 0
l = 0
c = 0
for i in range(n) :
	if a[i] == a[l] :
		c+=1
	else:
		b.append(c)
		c = 1
		l = i
b.append(c)
for i in range(len(b) - 1) :
	ans = max(ans, min(b[i], b[i+1])) 
print(ans*2)