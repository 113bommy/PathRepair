n,k = map(int,input().split())
if(k == 0):
	mini = 0
	maxi = 0
elif(k == n):
	mini = 0
	maxi = 0
else:
	mini = 1
	maxi = 2*k
	maxi = min(maxi,n-k)

print(mini, maxi)