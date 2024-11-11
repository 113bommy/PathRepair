lst=[]
k=int(input())
l=int(input())
m=int(input())
n=int(input())
d=int(input())
for i in range(k,d+1,k):
    lst.append(i)
for i in range(l,d+1,l):
    lst.append(i)
for i in range(m,d+1,m):
    lst.append(i)
for i in range(n,d+1,n):
    lst.append(i)
print(len(set(lst)))