q = int(input())
for _ in range(q):
	a = input()
	s = {}
	s['U'] = 0
	s['L'] = 0
	s['R'] = 0
	s['D'] = 0
	for x in a:
		s[x]+=1;
	if s["D"] == 0 or s['U'] == 0:
		if s["L"] and s["R"]:
			print(2)
			print('LR')
		else:
			print(0)
			print()
	elif s['L'] == 0 or s['R'] == 0:
		if s["U"] and s["D"]:
			print(2)
			print('UD')
		else:
			print(0)
			print()
	else:
		print(2*min(s['D'], s["U"])+2*min(s['R'], s["L"]))
		print('D'*(min(s['D'], s["U"])//2), "R"*(min(s['R'], s["L"])), "U"*min(s['D'], s["U"]), "L"*(min(s['R'], s["L"])), 'D'*((min(s['D'], s["U"])+1)//2), sep='')
