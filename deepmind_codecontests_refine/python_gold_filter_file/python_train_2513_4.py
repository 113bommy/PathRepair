n = int(input())
p = input()
count = 0
for i in range(n):
	if int(p[i])%2==0:
		count+=i+1
print(count)