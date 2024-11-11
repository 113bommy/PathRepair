import sys
input = sys.stdin.buffer.readline
def I(): return(list(map(int,input().split())))
def sieve(n):
	a=[1]*n
	for i in range(2,n):
	    if a[i]:
	        for j in range(i*i,n,i):
	            a[j]=0
	return a

n=int(input())
b=I()
marked=[-1]*n
marked[0]=1
# probablesums=[-1]*n
store={1:b[0]}
currmax=b[0]
for i in range(1,n):
	marked[i]=marked[i-1]+b[i]-b[i-1]-1
	store[marked[i]]=store.get(marked[i],0)+b[i]
	currmax=max(currmax,store[marked[i]])
print(currmax)