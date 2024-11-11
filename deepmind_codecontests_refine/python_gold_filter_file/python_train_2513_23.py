n = int(input())
s = input()
array = []

for i in range(n):
	if int(s[i]) % 2 == 0:
		array.append(i+1)

print(sum(array))