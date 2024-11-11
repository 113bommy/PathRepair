N = int(input())
X = input()

arr = [0 for _ in range(N+1)]
for i in range(1, N+1):
    cnt = bin(i).count('1')
    arr[i] = arr[i%cnt] + 1

x = int(X, 2)
pop = X.count('1')
plu = x % (pop+1)
mai = x % (pop-1) if pop>1 else 0

#bi = 1 << N
for i in range(N):
    #bi = bi >> 1
    if X[i] == '0':
        #res = (plu + bi % (pop+1)) % (pop+1)
        res = (plu + pow(2, N-1-i, pop+1)) % (pop+1)
    else:
        if pop == 1:
            print(0)
            continue
        #res = (mai - bi % (pop-1)) % (pop-1)
        res = (mai - pow(2, N-1-i, pop-1)) % (pop-1)
    print(arr[res] + 1)