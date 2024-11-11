n=int(input())
k=int(input())
t=[]
for i in range(n):
    t.append(int(input()))
t.sort()
c=0
while k>0:
    k-=t.pop()
    c+=1
print(c)