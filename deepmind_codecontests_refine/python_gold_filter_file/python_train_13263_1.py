a = set(map(int,input().split(',')))
a = list(a)
a.sort()
i = 0; s = ''; j = i
while i < len(a)-1:
    j = i
    while i < len(a)-1 and a[i+1] == a[i]+1:
          i += 1
          
    if i > j:
        s += str(a[j])+'-'+str(a[i])+','
    else:
        s += str(a[i])+','
    i += 1
if i < len(a):
    if a[i] == a[i-1]+1:
        s += str(a[j])+'-'+str(a[i])
    else:
        s += str(a[i])
print(s if s[-1] != ',' else s[0:-1])