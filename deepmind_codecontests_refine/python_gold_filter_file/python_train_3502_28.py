main=dict()
n,m=map(int,input().split())
for i in range(n):
	name,path=input().split()
	main[path+';']=name
for j in range(m):
	s=input()
	print(s,'#'+str(main[s.split()[1]]))