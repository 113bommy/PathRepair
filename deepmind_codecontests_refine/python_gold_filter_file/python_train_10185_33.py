A,B,C,X= [int(input()) for x in range(4)] 
ans = 0
for a in range(A+1):
	for b in range(B+1):
		for c in range(C+1):
			if 500*a+100*b+50*c == X:
				ans += 1
print(ans)