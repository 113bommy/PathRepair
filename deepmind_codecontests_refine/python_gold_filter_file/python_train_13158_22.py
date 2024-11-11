import itertools 
n,k=map(int,input().split())
ar=list(map(int,input().split()))
arr=list(itertools.accumulate(ar))
summ1,summ=0,0
S=[]
#print(arr)
for i in range(n-k+1):
  summ=arr[i+k-1]
  if i>0:
    summ-=summ1
  S.append(summ)
  summ1+=ar[i]

X,Y=0,k
x=0
for i in range(k,n-k+1):
    if S[x] < S[i-k]:
        x = i-k
   # print(x,i)
    if S[X]+S[Y] < S[x]+S[i]:
        X,Y = x,i
print(X+1,Y+1)
