n=int(input())
d=[int(x) for x in input().split()]
l=[int(x) for x in input().split()]
l.sort()
s,t=l[0],l[1]
s1,s2=0,0
for i in range(s-1,t-1):
    s1+=d[i]
#print(s1)

s2=sum(d)-s1
#print(s2)
print(min(s1,s2))
