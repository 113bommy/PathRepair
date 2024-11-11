from collections import Counter
n=int(input())
l=[]
for i in range(n):
    h,m=map(int,input().split())
    l.append(h*60+m)
d=Counter(l)
print (d.most_common(1)[0][1])
