n = int(input())
a = []
b = []
for i in range(2*n-2):
    f= input()
    b.append([len(f), [f, i]])
    a.append([len(f), f])
a.sort()
b.sort()
for i in range(len(a)):
    a[i] = a[i][1]
    b[i] = b[i][1]
s=''
x=['']*(2*n-2)
k=1
if a[-2][:-1] != a[-1][1:]:
    s=a[-2][0]+a[-1]
elif a[-1][:-1] != a[-2][1:]:
    s=a[-1][0]+a[-2]
else:
    s=a[-1][0]+a[-2]
    k = 0 
    for i in range(1, 2*n-2, 2):
        if a[i] == s[:len(a[i])] and a[i-1] == s[-len(a[i]):]:
            x[b[i][1]]='P'
            x[b[i-1][1]]='S'
        elif a[i-1] == s[:len(a[i])] and a[i] == s[-len(a[i]):]:
            x[b[i-1][1]]='P'
            x[b[i][1]]='S'    
        else:
            k=1
            s=a[-2][0]+a[-1]
            x=['']*(2*n-2)
if k == 1:
    for i in range(1, 2*n-2, 2):
        if a[i] == s[:len(a[i])] and a[i-1] == s[-len(a[i]):]:
            x[b[i][1]]='P'
            x[b[i-1][1]]='S'
        elif a[i-1] == s[:len(a[i])] and a[i] == s[-len(a[i]):]:
            x[b[i-1][1]]='P'
            x[b[i][1]]='S'
print(*x, sep='')
