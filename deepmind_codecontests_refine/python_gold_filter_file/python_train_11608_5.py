n=int(input())
a=list(map(int,input().split()))

# arr=sorted(arr,key=lambda  item:item[0])
d={}
for i in a:
	if i in d:
		d[i]+=1
	else:
		d[i]=1
mm=0
xx=0
for key,value in d.items():
	if mm<value:
		mm=value
		xx=key 
pos=[]
for key,value in d.items():
	if mm==value:
		pos.append(key)
# for x in pos:
# 	start=0
# 	end=n-1
# 	while start<=end:
# 		
po=[]
for i in range(max(a)+10):
	po.append([])
for i in range(len(a)):
	po[a[i]].append(i)
ans=10000000000
ii=-1
jj=-1
for i in pos:
	xx=po[i][-1]-po[i][0]+1
	if xx<ans:
		ans=xx
		ii=po[i][-1]+1
		jj=po[i][0]+1
print(min(ii,jj),max(ii,jj))
