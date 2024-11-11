vowels = ['a','e','i','u','o','y']
n = int(input())
s = input()

ans = s[0]

l = s[0]
i = 1
while True:
	if i == n:
		break

	r = s[i]

	if (l in vowels) and (r in vowels):
		i += 1
	else:
		ans += r
		l = r
		i += 1

print(ans)
