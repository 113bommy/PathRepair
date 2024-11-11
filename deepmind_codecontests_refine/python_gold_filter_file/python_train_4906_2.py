n = int(input())
l = list(map(int, input().split()))

one,many = [],[]
a,b,c = 0,0,0
for i,d in enumerate(l):
    if d==1:
        one.append(i+1)
        a+=1
    else:
        many.append((i+1,d))
        b+=1
        c+=d

if c-2*b+2<a:
    print("NO")
    exit()

print("YES",b+ min(a, min(a,2))-1)
print(n-1)

left = []
dia  = []
if one:
    dia.append(one.pop())
for i,d in many:
    dia.append(i)
    if d>2:
        left.append((i,d-2))
if one:
    dia.append(one.pop())
for i in range(len(dia)-1):
    print(dia[i], dia[i+1])
while one:
    i,d = left.pop()
    print(i, one.pop())
    if d>1:
        left.append((i,d-1))