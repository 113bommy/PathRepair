#!/usr/bin/env python3
def ri():
    return map(int, input().split())

dates = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

m, d = ri()

tot = (dates[m-1] + d - 1)

ans = tot//7
if tot % 7:
    ans += 1

print(ans)


