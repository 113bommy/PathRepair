n=int(input())
d=(list(map(int,input().split())))
sd=sorted(list(set(d)))
m=min(sd)
s=sum(d)
def no(s):
    r=[]
    for i in range(1,int(s**0.5)+1):
        if s%i==0: r.append(i)
    r.append(s)
    return r 
mm=int(min((s-i-m+i/t+t*m)for i in sd for t in no(i)))
print(mm)
