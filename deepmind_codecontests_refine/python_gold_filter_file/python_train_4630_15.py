n = input()
a = list(map(int, input().split()))
 
def counto(a):
    c1 = 0
    c2 = 0
    c3 = 0
    for i in range(len(a)):
        if a[i] == 1:
            c1+=1
        elif a[i] == 2:
            c2+=1
        else:
            c3+=1
    return min(c1, c2, c3)
    
minc = counto(a)
t1 = 0
t2 = 0
t3 = 0
result = [minc * [] for i in range(minc)]
for i in range(len(a)):
    if a[i] == 1:
        if t1 < minc:
            result[t1].append(i+1)
            t1+=1
    elif a[i] == 2:
        if t2 < minc:
            result[t2].append(i+1)
            t2+=1
    else:
        if t3 < minc:
            result[t3].append(i+1)
            t3+=1
printed = True
if len(result) == 0:
    print(0)
else:
    for i in range(len(result)):
        if printed == True:
            n = len(result)
            print(n)
            printed = False
        print(' '.join(map(str, result[i])))