b=list(map(int,input().split()))
m=b[0]
a=0
for i in range (3):
	if b[i]>m:
		m=b[i]
		a=i
ass=0
for i in range(3):
	if a!=i:
		ass=ass+b[i]

if ass>m:
	print("0")
else:
	print(m-ass+1)