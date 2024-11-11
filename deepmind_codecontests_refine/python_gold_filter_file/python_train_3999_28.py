n = int(input())
k = 1
sp = [int(input()) for i in range(n)]
if n == 1:
    print(1)
else:
    for i in range(1,n):
        if sp[i-1]%10 == sp[i]//10:
            k += 1
    print(k)
