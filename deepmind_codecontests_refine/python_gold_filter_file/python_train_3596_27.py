n , x = map(int,input().split())
p = 0
for _ in range(n):
    m = input().split()
    if '-' in m and x-int(m[1])>=0:
        x = x-int(m[1])
    elif '+' in m:
        x = x+int(m[1])
    else:
        p+=1
print(x,p)
