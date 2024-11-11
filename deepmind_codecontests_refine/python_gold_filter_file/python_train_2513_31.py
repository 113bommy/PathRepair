n = int(input())
s = input()
summ = 0
for i in range(len(s)):
	if int(s[i]) % 2 == 0:
		summ += i + 1
print(summ)