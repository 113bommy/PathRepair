n,m=map(int,input().split())
s1=input().split()
s2=input().split()
l=[]
for i in range(n*m):
	l.append(s1[i%n]+s2[i%m])
for i in range(int(input())):
	k=int(input())
	print (l[(k-1)%(n*m)])