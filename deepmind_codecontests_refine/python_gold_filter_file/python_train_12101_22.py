t = int(input())
for _ in range(t):
    n,k=map(int,input().split())
    i = 1
    j = 0
    while j+i < k:
        j+=i
        i+=1
    l = k-j-1
    r = ['a']*n
    r[i] = 'b'
    r[l] = 'b'
    r.reverse()
    print("".join(r))