n=int(input())
a=input()
b=list(a)
'''print(b)'''
if n==1:
	print(a)
else:
	f=1
	for i in range (len(b)-1):
		if ord(b[i])>ord(b[i+1]):
			del b[i]
			f=0
			break
	if f == 1:
		del b[-1]
	print(''.join(map(str,b)))			


			
	
		
		
