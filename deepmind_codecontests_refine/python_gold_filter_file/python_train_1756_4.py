from collections import Counter

n = int(input())
a = list(map(int, input().split()))

c = Counter(a)
m = max(a)



flag = True

for i in range(1, m+1):
    if i<m//2:
        if c[i]!=0:
            flag = False
    elif i==m//2:
        if m%2 == 0:
            if c[i]!=1:
                flag = False
                break
        else:
            if c[i]!=0:
                flag = False
                break
    elif i == m//2+1:
        if m%2 == 0:
            if c[i]<2:
                flag = False
                break
        else:
            if c[i]!=2:
                flag = False
                break
    else:
        if c[i]<2:
            flag = False
            break

print('Possible' if flag else 'Impossible')