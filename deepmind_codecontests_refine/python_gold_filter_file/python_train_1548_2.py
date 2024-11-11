def setGroup(a):
    l = len(a)
    i = 0
    b = []
    while i < l:
        if a[i] < a[i+1]:
            b.append(a[i + 1] - a[i])
        elif  a[i] > a[i+1]:
            b.append(a[i] - a[i+1])
        else:
            b.append(a[i])
        i += 2
    return b
        
n = int(input())
i = 0
a =[]
while i < 2**n:
    a.append(int(input()))
    i += 1
while len(a) > 1:
    a = setGroup(a)
print(a[0])