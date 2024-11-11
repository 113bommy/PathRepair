*s,=map(int,input())
n=len(s)
a=sum(s[::2])+n//2-sum(s[1::2])
print(min(a,n-a))