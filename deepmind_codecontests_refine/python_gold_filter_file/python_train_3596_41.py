n,x = map(int,input().split())

cnt = 0
for i in range(n):
    s,d = input().split()
    d = int(d)
    if s == '+':
        x += d
    elif s == '-':
        if x >= d :
            x-=d
        elif x<d:
            cnt +=1

print(str(x) + " " + str(cnt))