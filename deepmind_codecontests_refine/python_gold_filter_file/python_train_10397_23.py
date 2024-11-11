n,m = input().split()
k=int(n)
l = list(input().split())

for i in range(k,100000):
    for e in l:
        if e in str(i):
            break
    else:
        print(i)
        break
