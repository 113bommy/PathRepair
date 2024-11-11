
def mi():
	return map(int, input().split())

n,m,q = mi()
s = list(input())
t = list(input())
pre1 = [0]*n
pre2 = [0]*n
if n>=m:
	for i in range(n-m+1):
		if (s[i:i+m]==t):
			pre1[i+m-1] = 1
			pre2[i] = 1
	for i in range(1,n):
		pre1[i]+=pre1[i-1]
		pre2[i]+=pre2[i-1]
pre1.insert(0,0)
pre2.insert(0,0)


while q:
	q-=1
	l,r = mi()
	s1, s2 = 0,0
	#for i in range(l, r+1):
		#s1+=pre1[i]
		#s2+=pre2[i]
	if m>n:
		print (0)
		continue
	if r<m or r-l+1<m or n-l+1<m:
		print (0)
		continue
	s1 = pre1[r]-pre1[l-1+m-1]
	s2 = pre2[r-m+1]-pre2[l-1]
	if s1>0 and s2>0:
		print (min(s1,s2))
	else:
		print (0)
	
