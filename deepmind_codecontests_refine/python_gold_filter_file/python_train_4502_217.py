def f(p):
    return (p-1)//2
k=int(input())
r=[]
for i in range(0,k):
    p=int(input())
    r.append(f(p))
for i in r:
    print(i)