N, A, B = map(int, input().split())
 
if (B-A) % 2 == 0:
	print( (B-A) // 2 )
else:
	print(min([1+N-B+(B-A)//2, A+(B-A)//2]))