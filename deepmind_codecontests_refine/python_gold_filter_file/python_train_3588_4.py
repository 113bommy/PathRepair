s1 = input()
s2 = input()
n = int(input())
h = []
a = []
for i in range(n):
    k = input().split()
    if k[1] == 'h':
        if (h.count(k[2]) == 0) and k[3]=='y':
            h.append(k[2])
        elif h.count(k[2]) == 1:
            h.append(k[2])
            print(s1,k[2],k[0])
        if (h.count(k[2]) == 0) and k[3]=='r':
            h.append(k[2])
            h.append(k[2])
            print(s1,k[2],k[0])
    else:
        if (a.count(k[2]) == 0) and k[3]=='y':
            a.append(k[2])
        elif a.count(k[2]) == 1:
            a.append(k[2])
            print(s2,k[2],k[0])
        if (a.count(k[2]) == 0) and k[3]=='r':
            a.append(k[2])
            a.append(k[2])
            print(s2,k[2],k[0])

