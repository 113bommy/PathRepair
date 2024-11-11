leng = int(input())
l = list(map(int,input().split(" ")))
l1 = [0]*leng
for x in range(leng):
	l1[x] = (l[x]*leng)+(x)

for x in range(leng):
	ind = l1[x]//leng
	l[ind-1] = (l1[x]%leng)+1

for x in range(leng):
	print(l[x],end = " ")