s = input()
l,r,ans = 0,len(s)-1,0
while l<r:
	if s[l]==s[r]: l,r = l+1,r-1
	elif s[l]=="x": l,ans = l+1,ans+1
	elif s[r]=="x": r,ans = r-1,ans+1
	else: break
if l>=r: print(ans)
else: print(-1)