arr=[]
x=input()
xx=x.split(' ')
n=int(xx[0])
f=int(xx[1])
a=[]
s= 0
for i in range(n):
	x = input()
	xx = x.split(' ')
	k = int(xx[0])
	l = int(xx[1])
	s += min(k, l);
	if k >= l:
		a.append(0)
	else:
			a.append(min(2 * k, l) - min(k, l))
a.sort(reverse=True)
i = 0
while f>0 and i < n:
	if a[i] > 0:
		s += a[i]
		f -=1
	i+=1
print(s)