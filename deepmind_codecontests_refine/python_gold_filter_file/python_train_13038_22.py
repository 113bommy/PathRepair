def ans(a,b) :
    if a%2 == 0 :
        return b*(a/2)
    else :
        return b*(a//2)+b//2+b%2
n=int(input())
l=[]
for i in range(n):
    m=[int(j) for j in input().split()]
    l.append(m)
for i in range(n):
    k=ans(l[i][0],l[i][1])
    print(int(k))