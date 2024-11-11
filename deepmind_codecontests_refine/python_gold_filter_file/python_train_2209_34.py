t = int(input())

for i in range(t):
	s = int(input())
	
	curr = s
	ext = 0
	
	while(curr>=10):
		ext += int( curr/10 )
		curr = curr%10 + int( curr/10 )
		
	print(s+ext)
		