n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
k = []
j = 0
na= 0
c = 0
if sum(a)<sum(b):
    print(-1)
else:
    for i in range(n):
        if a[i]<b[i]:
            na +=b[i]-a[i]
            c+=1
        elif a[i] > b[i]:
            k.append(a[i]-b[i])
    k.sort()
    k = k[::-1]
    while na > 0:
        na -=k[j]
        c +=1
        j+=1
    print(c)
