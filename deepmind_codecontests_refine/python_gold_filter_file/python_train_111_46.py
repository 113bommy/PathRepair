n=int(input())
l=list(map(int,input().strip().split()))
s=sum(l)
m=max(l)
s1=(2*(s)+1+(n-1))//n
print (max(m,s1))