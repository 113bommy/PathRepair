cube  = int(input())
level = 0
out   = 1

if cube == 1:
	level = 1
else:
	while cube > 0:
		out   += 1 
		
		cout = 0
		for i in range(out):
			cout += i
			
		cube  -= cout
		
		if cube >= 0:
			level += 1
			
print(level)