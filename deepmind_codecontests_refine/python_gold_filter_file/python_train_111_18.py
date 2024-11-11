n = int(input())
ll = list(map(int,input().split()))
lsum=sum(ll)
k = max(ll)
while n*k-lsum <= lsum :
    k=k+1
print(k)