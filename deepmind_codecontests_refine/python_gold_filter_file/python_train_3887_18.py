n=int(input())
x=sorted(list(map(int,input().split(' '))))
c=v=0
while v <=sum(x):
    c+=1
    v+=x.pop()
print(c)