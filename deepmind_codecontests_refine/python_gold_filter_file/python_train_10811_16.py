n,ans = int(input()),0
s = list(input())
for i in range(n+1):ans = max(ans,s[:i].count("I")-s[:i].count("D"))
print(ans)