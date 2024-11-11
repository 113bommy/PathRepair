import sys
cnt = 0
ans = 0
for s in sys.stdin:
	if s[0] == '+':
		cnt+=1
	elif s[0] == '-':
		cnt-=1
	else:
		k = s.split(':')
		ans+=(len(k[1])-1)*cnt
print(ans)
