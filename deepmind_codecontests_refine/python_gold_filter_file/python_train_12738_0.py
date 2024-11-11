#!/usr/bin/env python3

if __name__ == "__main__":
	n = int(input())
	if n % 2 == 0:
		lst = list(str(x) for x in range(1, n+1))
		i = 0
		while i <= n-2:
			lst[i], lst[i+1] = lst[i+1], lst[i]
			i += 2 
		print(" ".join(lst))
	else:	
		print(-1)
