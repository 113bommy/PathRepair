n = int(input())
list1 = list(map(int, input().split()))

x=0
ans=0
dic={}
list2 = []
for i in range(n):
	list2.append(x)
	x+=list1[n-1-i]
	dic[list1[i]]=dic.get(list1[i],0)+1
	
list2.reverse()

for i in range(n):
	ans+=list2[i]-(n-1-i)*list1[i]
	ans-=dic.get(list1[i]+1,0)
	ans+=dic.get(list1[i]-1,0)
	dic[list1[i]]-=1
	
print(ans)