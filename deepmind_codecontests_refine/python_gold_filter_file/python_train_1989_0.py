#yeh dil maange more
n = int(input())
m = int(input())
a = list()
for i in range(n):
    A = int(input())
    a.append(A)
maxofa = max(a)
mx = m+maxofa
imn,ind = 0,a[n-1]
for i in range(m):
    ind = 10000
    for i in range(n):
        if a[i]<=ind:
            ind = a[i]
            imn = i
    a[imn] +=1
mn = max(a)
print(mn,mx)