n, m = list(map(int, input().split()))

if (m == 0):
	Min = n; Max = n;
else:
	Min = 0 if (m >= (n//2 if (n%2==0) else n//2 + 1)) else (n- m*2)
	for i in range(n, 0, -1):
		nEdges =  (i*(i-1))//2
		if ( nEdges == m ):
			Max = n - i
			break
		else:
			if ( nEdges < m ):
				Max = n - i - 1
				break

print(Min, Max)

