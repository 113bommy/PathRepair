def game(s):
	l=0
	r=0
	ans=[0]
	for i in s:
		if i=="L":
			ans.append(l-1)
			l-=1
		else:
			ans.append(r+1)
			r+=1
	print(len(ans))
n=int(input())
s=input()
game(s)
