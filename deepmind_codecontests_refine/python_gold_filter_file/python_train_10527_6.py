n = input().split()
n, k = int(n[0]), int(n[1])
x = 0
for i in range(1,10**8):
    if n%i==0:
        if (n//i)<k:
            x = i*k+n//i
            break
print(x)