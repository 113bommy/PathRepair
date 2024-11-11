 
def solve(lst,k):
	minVal = max(lst)
	ind=lst[0]
	ans = 0
	for i in range(len(lst)):
		if lst[i] < minVal:
			minVal=lst[i]
			ind=i
	for i in range(len(lst)):
		if ind==i:
			continue
		ans += ((k-lst[i])//minVal)
	return ans

m = int(input())
for i in range(m):
	k,m = map(int,input().split(' '))
	lst = list(map(int,input().split(' ')))
	print(solve(lst,m))