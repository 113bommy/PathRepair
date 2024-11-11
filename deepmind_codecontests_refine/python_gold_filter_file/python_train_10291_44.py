a = [0,1,3,1,2,1,2,1,1,2,1,2,1]
x,y = map(int,input().split())

if a[x] == a[y]:
	print("Yes")
else:
    print("No")