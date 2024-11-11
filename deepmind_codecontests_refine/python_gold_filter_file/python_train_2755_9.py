n = int(input())
x = input()
x = x.split(' ')
a = []
c = []
b=[]
for i in range(0, len(x)):
    x[i] = int(x[i])
    
for i in range (1, len(x) - 1):
    a.clear()
    a.extend(x) 
    a.remove(a[i])
    for j in range(0, len(a) - 1):
        b.append(a[j + 1] - a[j])
    c.append(max(b))
    b=[]
print(min(c))
