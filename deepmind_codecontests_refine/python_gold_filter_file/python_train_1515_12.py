cards=list(map(int,input().split()))
c=0
for i in cards:
	if cards.count(i)>=2 and i*cards.count(i)>c:
		if cards.count(i)>3:
			c=i*3
		else: c=i*cards.count(i)

print (sum(cards)-c)

