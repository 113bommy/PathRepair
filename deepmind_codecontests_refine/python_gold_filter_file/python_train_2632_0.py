n = int(input())
mn = 999999999999

for i in range(1, int(n**(1/3))+1):
    if n%i==0:
        for j in range(1, int((n//i)**(1/2))+1):
            if (n/i) % j == 0:
                k = (n//i)//j
                mn = min(mn, (i+1)*(k+2)*(j+2))

print(mn-n, (9*n+9-n))