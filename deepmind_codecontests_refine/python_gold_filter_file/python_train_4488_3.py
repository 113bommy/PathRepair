n,k=map(int,input().split())
s=input()
se=set(list(s))
l=[]
for i in se:
    l.append(s.count(i))
if(len(se)>=k):
    print(min(l)*k)
    exit(0)
print(0)