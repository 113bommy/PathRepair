N=int(input())
l=[1,3,6,10,15,21,28,36,45]
a=0
for i in range(2,1000001):
    t=0
    while N%i==0:
        t+=1
        N//=i
    if t:
        for i in range(9):
            if t<l[i]:
                a+=i
                break
if N>1000000:
    a+=1
print(a)