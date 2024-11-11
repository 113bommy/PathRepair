N,K = map(int,input().split())
D = input().split()

for i in range(N,100000):
    match = False
    for s in str(i):
        if s in D:
            match = True
            break
    if not match:
        print(i)
        break