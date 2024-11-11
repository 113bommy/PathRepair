n,m=[int(n) for n in input().split()]
s=[]*n
t=[]*m
s=input().split()
t=input().split()
no=int(input())
ans=list()
for i in range(0,no):
	req_no=int(input())
	ans=ans+[s[(req_no-1)%n]+t[(req_no-1)%m]]
for i in ans:
	print(i)
