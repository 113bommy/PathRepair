a,b = [int(x) for x in input().split()]
i=1
a -= b
count = 0
if a == 0:
	print('infinity')
else:
	while i*i <= a:
		if a%i == 0:
			if i*i == a:
				count += 1
			else:
				count+= 2
				if a//i<=b:
					count -= 1
			if i<=b:
				count -= 1
		i+=1
	print(count)