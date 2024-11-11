n,v = map(int,input().split())
otvet = ''
for i in range(n):
    l = list(map(int,input().split()))
    l = sorted(l)
    for j in range(1,l[0]+1):
        if l[j] < v:
            otvet = otvet + str(i+1) + ' '
        break
print(len(otvet.split()))
print(otvet)
