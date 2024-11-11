def razl(x):
    t=True
    x=''.join(sorted(list(str(x))))
    for i in range(len(str(x))-1):
        if str(x)[i]==str(x)[i+1]:
            t=False
            break
    return t
a,b=map(int,input().split())
x=-1
for i in range(a,b+1):
    if razl(i):
        x=i
        break
print(x)