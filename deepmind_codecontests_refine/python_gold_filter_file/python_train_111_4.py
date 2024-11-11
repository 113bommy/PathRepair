n=int(input())
l=list(map(int,input().split()))
k=(2*sum(l))/n
if k<max(l):print(max(l))
else:print(int(k)+1)