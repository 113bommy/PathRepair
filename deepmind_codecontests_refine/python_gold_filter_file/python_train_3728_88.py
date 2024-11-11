x,y,z,k = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
c = list(map(int,input().split()))

li  = []

for i in a:
    for j in b:
        li.append(i+j)

li.sort(reverse=True)
li = li[:k]

lin = []

for i in li:
    for j in c:
        lin.append(i+j)

lin.sort(reverse=True)

for i in range(k):
    print(lin[i])