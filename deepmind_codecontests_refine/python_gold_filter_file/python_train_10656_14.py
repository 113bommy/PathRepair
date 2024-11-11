a = []
b =  []
n = int(input())
f = 0
d = 0
q = -1

for i in range (n):
    c = input().split()
    a.append(int(c[0]))
    b.append(int(c[1]))
f=min(a)
d=max(b)

for i in range (len(a)):
    if(a[i] == f and b[i]==d):
        q=i+1

print(q)   