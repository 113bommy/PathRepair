n,m = map(int, input().split())

ct = 0
for _ in range(n):
    w = list(map(int, input().split()))
    for i in range(0,2*m,2):
        #print(i)
        if w[i] == 1 or w[i+1] == 1:
            ct += 1
print(ct)