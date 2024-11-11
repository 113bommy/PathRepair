n, k = map( int, input().split() )
x = input()

pos_G = pos_T = 0

for i in range(n):
	if x[i] == 'G':
		pos_G = i
	elif x[i] == 'T':
		pos_T = i
		
if pos_G < pos_T:
	while pos_G+k <= pos_T:
		pos_G += k
		if pos_G == pos_T:
			print( "YES" )
			exit(0)
		elif x[pos_G] == '#':
			break
else:
	while pos_T+k <= pos_G:
		pos_T += k
		if pos_G == pos_T:
			print( "YES" )
			exit(0)
		elif x[pos_T] == '#':
			break
			
print( "NO" )
	