n,c = map(int,input().split())
p = list(map(int,input().split()))
t = list(map(int,input().split()))

rt=0
lt =0
pl=0
pr=0
tl =0
for i in range(n):
	pl += max(0,p[i] -c*(tl + t[i])) 
	tl += t[i]
tl=0
for i in range(n)[::-1]:
	pr+= max(0,p[i] -c*(tl+t[i]))
	tl += t[i]

if pr>pl:
	print('Radewoosh')
elif pr==pl:
	print('Tie')
else:
	print('Limak')
