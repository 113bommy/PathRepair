#!/usr/bin/env python3
def ri():
    return map(int, input().split())


n = int(input())
k = input()

ans = 0
p = 0
while True:
    kk = k[:]
    for i in range(len(kk)):
        if int(kk[i]) == 0 and len(kk[i:]) != 1:
            continue
        if n > int(kk[i:]):
            ans += int(kk[i:])*(n**p)
            p += 1
            if i == 0:
                print(ans)
                exit()
            k = kk[:i]
            break




