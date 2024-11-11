def funky(n):
	arr = [(i*(i+1))/2 for i in range(1, 2*int(n**0.5) + 1)]
	i = 0
	j = len(arr)-1
	while i <= j:
		s = arr[i] + arr[j]
		if s == n:
			return True
		elif s < n:
			i+= 1
		else:
			j -= 1
	return False

n = int(input())
ans = funky(n)
print("YES" if ans else "NO")