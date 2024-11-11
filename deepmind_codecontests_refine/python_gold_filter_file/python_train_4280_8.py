n , m = map(int,input().split())
lst = [[] for i in range(n +1)]

for i in range(m):
    x , y = map(int, input().split())
    lst[x].append(y)
    lst[y].append(x)

#print(lst)

a = [0]*(n+1)
b = [0]*(n+1)
c = 0

def func(n):
    global a, b, c, lst
    a[n] = 1
    for j in lst[n]:
        if a[j] == 1 and b[n] != j:
            c += 1
        if(not a[j]):
            b[j] = n
            func(j)
    a[n] = 2
            
func(1)
if c -1 or 0 in a[1: ]:
    print("NO")
else:
    print("FHTAGN!")
