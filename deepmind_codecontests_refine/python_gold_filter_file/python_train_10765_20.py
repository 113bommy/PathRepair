n = input()
n = ''.join(reversed(n))
offset = 5
for i in range(len(n)):
	s = ""
	count = 4
	value = int(n[i])
	leading = value
	if value >= offset:
		s += "-O|"
		leading = value - offset
	else:
		s += "O-|"
	for j in range(leading):
		s+="O"
	if leading<=offset-1:
		s+="-"
	for j in range(leading,offset-1):
		s+="O"
	print(s)