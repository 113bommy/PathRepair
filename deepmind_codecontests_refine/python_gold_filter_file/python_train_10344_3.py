n=int(input())
lst1=list(map(int,input().split()))
dict1={}
for i in range(n):
	if lst1[i] in dict1:
		continue
	else:
		dict1[lst1[i]]=i+1
lst2=lst1[::-1]
dict2={}
for i in range(n):
	if lst2[i] in dict2:
		continue
	else:
		dict2[lst2[i]]=i+1


m=int(input())
query=list(map(int,input().split()))
first=second=0
for i in query:
	first+=dict1[i]
	second+=dict2[i]
print(first,second)