k=int(input())
l=int(input())
m=int(input())
n=int(input())
d=int(input())
e={}
if (k>d and l>d and m>d and n>d ):
    print(0)
    exit(0)
for i in range(0,d+1,k):
    if i not in e:
        e[i]=0
for i in range(0,d+1,l):
    if i not in e:
        e[i]=0
for i in range(0,d+1,m):
    if i not in e:
        e[i]=0
for i in range(0,d+1,n):
    if i not in e:
        e[i]=0
for i in range(0,d+1,n):
    if i not in e:
        e[i]=0
print(len(e)-1)
