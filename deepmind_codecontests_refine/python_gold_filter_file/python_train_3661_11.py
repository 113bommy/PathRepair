n,m=map(int,input().split())
arr=list(map(int,input().split()))
fr=[0]*n
br=[0]*n
cyc=[0]*(n-1)
maxind=0
for i in range(n):
	if arr[i]>arr[maxind]:
		maxind=i
pick=arr[0]
last=-1
for i in range(n):
	if i>=maxind:
		fr[i]=arr[maxind]
		if i!=n-1:
			br[i]=arr[i+1]
			cyc[i]=arr[i+1]
		else:
			br[i]=cyc[0]
	else:
		fr[i]=pick
		br[i]=arr[i+1]
		if pick<arr[i+1]:
			cyc[i]=pick
			pick=arr[i+1]
		else:
			cyc[i]=br[i]


# print(fr)
# print(br)
# print(cyc)
for i in range(m):
	k=int(input())
	if k<=n:
		print(fr[k-1],br[k-1])
	else:
		print(arr[maxind],cyc[k%(n-1)-1])
