a=list(map(int,input().split()))
if a[1]%a[2]==0:					
	s=(a[1]//a[2])
else:
	s=(a[1]//a[2])+1	
s=s*a[0]
if s%a[3]==0:
   print(s//a[3])
else:
	print(1+(s//a[3]))