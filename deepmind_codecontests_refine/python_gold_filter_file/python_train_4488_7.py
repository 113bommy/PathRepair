a="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
n,k=map(int,input().split())
s=input()
l=[]
for i in range(k):
    l.append(s.count(a[i]))
print(min(l)*k)