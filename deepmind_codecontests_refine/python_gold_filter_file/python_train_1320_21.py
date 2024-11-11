a,b = map(int,input().split())
t = max(a,b)
l = 6-t+1
if l%2 == 0:
	t = str(l//2)
	k = t+"/"+"3"
	if k == "3/3":
		print("1/1")
	else:
		print(t+"/"+"3")
elif l == 3:
	print("1/2")
elif l%2 == 1:
	t = str(l)
	print(t+"/"+"6")

