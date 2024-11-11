from collections import Counter
n=int(input())
s=list(map(int,input().split()))
sm=Counter(s)
su=set()

for i in sm.keys():
	if sm[i]==1:
		su.add(i)
j=-1
i=0
while i<n and j==-1:
	if sm[s[i]]>=3:j=i
	i+=1

if len(su)%2==1:
	if j==-1:print("NO")
	else:
		print('YES')
		cnt=0
		ch=""
		i=0
		while i<n:
			if (s[i] in su and cnt<len(su)//2) or i==j :
				ch+="A"
				if i!=j:cnt+=1
			else:
				ch+="B"
			i+=1
		print(ch)

else:
	print('YES')
	cnt=0
	ch=""
	i=0
	while i<n:
		if s[i] in su and cnt<len(su)//2:
			ch+="A"
			cnt+=1
		else:
			ch+="B"
		i+=1
	print(ch)
