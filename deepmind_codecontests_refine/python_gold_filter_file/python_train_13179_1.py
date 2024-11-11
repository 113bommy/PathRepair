# import sys
# sys.stdin = open("test.in","r")
# sys.stdout = open("test.out.py","w")
n=int(input())
a=[list(map(int,input().split())) for i in range(n)]
for i in range(n):
	for j in range(n):
		if a[i][j]!=1 :
			f=0
			for x in range(n):
				for y in range(n):
					if(a[i][j]==a[i][x]+a[y][j]):
						f+=1
			if f==0 :
				print("No")
				exit()
print("Yes")