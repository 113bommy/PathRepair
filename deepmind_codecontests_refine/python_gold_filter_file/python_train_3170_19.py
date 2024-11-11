n = int(input())
a=1
x = input()
b=x
for _ in range(1,n):
	v = input()
	if x==v:
		a+=1
	else:
		b=v
i = print(x) if a>n//2 else print(b)
