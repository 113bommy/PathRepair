n=int(input())
l=[2,1]
for i in range(n):
    l.append(l[i]+l[i+1])
print(l[n])