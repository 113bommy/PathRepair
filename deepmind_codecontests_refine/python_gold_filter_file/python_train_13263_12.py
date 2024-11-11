l=list(set(list(map(int,input().split(",")))))
l.sort()
a=""
for i in l:
    if i-1 not in l:a+=','+str(i)
    elif i+1 not in l:a+='-'+str(i)
print(a[1:])