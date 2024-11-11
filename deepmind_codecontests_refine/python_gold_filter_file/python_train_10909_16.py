n=int(input())
s=input()
a=0
for i in range(1000):
    t=str(i).zfill(3)
    p=0
    for j in s:
        if j==t[p]:
            p+=1
        if p==3:
            #print(t,p)
            break
    if p==3:
        a+=1
print(a)