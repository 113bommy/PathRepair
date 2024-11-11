#-*-coding:utf8;-*-
#qpy:3
#qpy:console
t, k = map(int, input().split()) 
mod = 1000000007 
res = [x for x in range(1, k+1)] 
for i in range(k, 100001): 
    res.append((res[i - 1] + res[i - k] + 1) % mod) 
for i in range(t):
    a, b = map(int, input().split()) 
    print(str((res[b] - res[a - 1]) % mod))