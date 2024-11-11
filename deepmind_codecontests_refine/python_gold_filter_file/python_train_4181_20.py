n = int(input()) 
ot = [] 
for i in range(n):
    x = [] 
    x.extend(input()) 
    x.sort()
    ans = 'Yes'
    if len(x) > len(set(x)):
        ans = 'No' 
    for j in range(1, len(x)):
        if ord(x[j-1]) + 1 != ord(x[j]):
            ans = 'No'
            break
    ot.append(ans)
print('\n'.join(ot))
