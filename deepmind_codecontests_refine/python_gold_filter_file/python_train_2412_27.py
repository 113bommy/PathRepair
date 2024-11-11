r=int(input())
if r==1:print("NO");exit()
for i in range(1,int(r**0.5)):
	if (r-1-i-i**2)%(2*i)==0:
		print(i,(r-1-i-i**2)//(2*i))
		break
else:print("NO")