n,h=[int(x) for x in input().split()]
L=[int(x) for x in input().split()]
w=0
for i in range(n):
    if L[i]>h:
        w+=2
    else:
        w+=1
print(w)
