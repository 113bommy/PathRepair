I=lambda:list(map(int,input().split()))
for tc in range(int(input())):
	n,k=I()
	s=input().strip()
	ch="RGB"
	ans=10**9+7
	for ty in range(3):
		cur=0
		for i in range(k):
			if s[i]!=ch[(i+ty)%3]:
				cur+=1
		ans=min(ans,cur)
		for j in range(k,n):
			if s[j-k]!=ch[(j+ty-k)%3]:
				cur-=1
			if s[j]!=ch[(j+ty)%3]:
				cur+=1
			ans=min(ans,cur)
	print(ans)