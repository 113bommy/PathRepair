n=int(input())
l=[int(i) for i in input().split()]
l.sort()
l1=[i for i in range(2,n+1,2)]
l2=[i for i in range(1,n,2)]
s1=sum(abs(l1[i]-l[i]) for i in range(n//2))
s2=sum(abs(l2[i]-l[i]) for i in range(n//2))
#print(s1,s2)
print(min(s1,s2))