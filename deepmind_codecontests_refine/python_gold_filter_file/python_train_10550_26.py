n=int(input())
k=[]
for i in range(1,10**5):
    k.append((i*(i+1))//2)
c=0
s=set(k)
for j in s:
    if n-j in s:
        c=1
        break
(print("YES") if c==1 else print("NO"))


