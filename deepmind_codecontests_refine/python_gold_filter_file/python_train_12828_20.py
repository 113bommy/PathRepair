# n = int(input())
# arr = list(map(int,input().split()))

# maxsum=0
# maxsumAt=0
# for i in range(n):
	

# 	keep = arr[i]
# 	sum=keep

# 	for j in range(i-1,-1,-1):
# 		keep = min(keep,arr[j])
# 		sum+=keep

# 	keep = arr[i]
# 	for k in range(i+1,n):
# 		keep=min(keep,arr[k])
# 		sum+=keep
	
# 	if sum>maxsum:
# 		maxsum=sum
# 		maxsumAt=i

# # print(maxsumAt,maxsum)

# ans=[0]*n
# ans[maxsumAt]=arr[maxsumAt]
# i=maxsumAt
# keep = ans[maxsumAt]
# for j in range(i-1,-1,-1):
# 	# print(keep)
# 	keep = min(keep,arr[j])
# 	ans[j]=keep
# keep = ans[maxsumAt]
# for k in range(i+1,n):

# 	keep=min(keep,arr[k])
# 	ans[k]=keep
# print(*ans)

for t in range(int(input())):
	
	n,x,y = map(int,input().split())

	worst = min(n,x+y-1)

	#forbest
	# number = x+y+1
	# beginFrom= max(1,x+y+1-n)
	best=max(1,min(x+y+1-n,n))
	print(best,worst)
