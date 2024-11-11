#1244A in codeforces
t = int(input())
for _ in range(t):
	a,b,c,d,k = map(int,input().split())
	pens = a//c
	pencils = b//d
	if a>0 or b>0:
		if (a%c)>0:
			pens+=1
		if (b%d)>0:
			pencils+=1
	if pens+pencils<=k:
		print(str(pens)+" "+str(pencils))
	else:
		print(-1)