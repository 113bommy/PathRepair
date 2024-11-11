try:
	s = ''
	while True:
		s = s + input().lower()
except EOFError:
	[print(chr(o)+' : '+str(s.count(chr(o)))) for o in range(ord('a'),ord('z')+1)]