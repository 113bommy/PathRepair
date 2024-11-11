s=input().strip(" ")
s=s.strip('{')
s=s.strip('}')
s=s.split(", ")
l=[]
if s!=['']:
	for letter in s:
		if letter in l:
			continue
		else:
		    l = l+ [letter,]
print(len(l))