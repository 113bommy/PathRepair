
a,b,c,d=map(int,input().split())
if a-min(a,c,d)>=1 and b!=0:
	print(min(a,c,d)*256+min(b,(a-min(a,c,d)))*32)	
else:
	print(min(a,c,d)*256)