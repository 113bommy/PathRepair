n,m = map(int,input().split()); l = input()
h,k = l.index('G'),l.index('T')
c=0
if h>k:
	for i in range(max(0,h-m),k-1,-m):
		if l[i]=='#':c='NO';break
		elif l[i]=='T':c='YES';break
else:
	for i in range(h+m,k+1,m):
		if l[i]=='#':c='NO';break
		elif l[i]=='T':c='YES';break
print('NO') if c==0 else print(c)