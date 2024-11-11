ct = [0]*26

string = input()

for s in string:
	ct[ord(s)-ord('a')]+=1


t = []
u = []

for s in string:
	t.append(s)
	ct[ord(s)-ord('a')] -= 1
	# to get lexo minimal all previous chars must be already
	# part of final string
	while t and sum(ct[:ord(t[-1])-ord('a')])==0:
		u.append(t.pop())

print(*u,sep="")