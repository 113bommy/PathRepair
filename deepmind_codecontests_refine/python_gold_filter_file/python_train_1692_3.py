T = int(input())
for _ in range(T):
    a, b = list(map(int, input().split()))
#     print(a,b)
    big = max(bin(a)[2:], bin(b)[2:])
    small = min(bin(a)[2:], bin(b)[2:])
    window = len(small)
    idx = big.find(small)
    
    if idx!=0:
        print(-1)
    else:
        bits = len(big) - (idx + window)
        if big[idx+window:].find("1")!=-1:
            print(-1)
        else:
            a = bits//3 + (bits%3)//2 + (bits%3)%2
            print(a)