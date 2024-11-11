import sys
I=sys.stdin.readline
ans=""
for _ in range(int(I())):
	s=I()
	s=s[0:len(s)-1]
	#s.strip('\n')
	if 'R' not in s:
		ans+="{}\n".format(len(s)+1)
	elif "L" not in s:
		ans+="{}\n".format(1)
	else:
		r=[]
		i=0
		j=i
		while i<len(s) and j<len(s):
			if s[i]=="R":
				j=i+1
				while j<len(s):
					if s[j]=="R":
						r.append(j-i)
						break
					j+=1
			i+=1
		r.append(s.index("R")+1)
		r.append(s[::-1].index("R")+1)
		ans+="{}\n".format(max(r))


print(ans)
