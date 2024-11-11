a = [-1] * 2002
a[0] = 0
for i in range(int(input())):
    s, t= input().split()
    t = int(t) + 1
    #t = int(input())
    if(s[0] == 'w'):
        a[t] = a[0]
    elif a[t] >= 0:
        a[0] = max(a[0], a[t] + (1<<(t-1)))
print(a[0])
