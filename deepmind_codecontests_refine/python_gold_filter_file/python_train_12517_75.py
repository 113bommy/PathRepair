str = input()
yn = False
for i in str:
	if(i in 'HQ9'):
		yn = True
		break
if(yn):
	print("YES")
else:
	print("NO")