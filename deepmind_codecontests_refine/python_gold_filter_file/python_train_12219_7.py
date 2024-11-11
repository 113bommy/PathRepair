n=int(input())
x=list(map(int,input().split()))
chest=[]
biceps=[]
back=[]
for i in range(n):
	if i%3==0:
		chest.append(x[i])
	elif i%3==1:
		biceps.append(x[i])
	else:
		back.append(x[i])
chest=sum([0]+chest)
biceps = sum([0]+biceps)
back =sum([0]+back)
answer = max(chest,biceps,back)
if answer==chest:
	print('chest')
elif answer == biceps:
	print('biceps')
else:
	print('back')
