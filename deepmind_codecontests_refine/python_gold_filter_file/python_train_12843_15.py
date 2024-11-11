n,k=list(map(int ,input().split()))
a1=list(map(int ,input().split()))
count=0
for i in range(0,len(a1)):
	ele=str(a1[i])
	# print(ele)
	if(ele.count("4")+ele.count("7")<=k):
		count+=1
	

print(count)