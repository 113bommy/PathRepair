n = int(input())

old = []
new = []

for i in range(n):
    x = input().split(" ")
    
    try:
        c = new.index(x[0])
        new[c] = x[1]
    except:
        old.append(x[0])
        new.append(x[1])

print (len(old))
for i in range(len(old)):
    print (old[i]+" "+new[i])