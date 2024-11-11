n=int(input())
d=list(map(int,input().split()))
s=sum(d)
print(sum([x*(s-x) for x in d])//2)