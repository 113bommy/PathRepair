n=int(input())

a=[]

i=1
e=1

while i != n:
    e=((i+e)-1)%n+1
    a.append(e)
    i+=1
print(*a)
