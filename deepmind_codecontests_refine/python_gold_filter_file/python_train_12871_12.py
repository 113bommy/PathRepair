def eratosthenes(n):     # n - число, до которого хотим найти простые числа 
    sieve = list(range(n + 1))
    sieve[1] = 0    # без этой строки итоговый список будет содержать единицу
    for i in sieve:
        if i > 1:
            for j in range(i + i, len(sieve), i):
                sieve[j] = 0
    return sieve
a=[]
for i in eratosthenes(1000000):
    if i:
        a.append(i)
n,m=map(int,input().split())
if n==2 and m==1:
    print(3,3)
    print(1,2,3)
    exit()
for s in a:
    if s>=n:
        break
print(s,s)
for i in range(1,n-1):
    print(i,i+1,1)
print(i+1,i+2,s-n+2)
if m>=n:
    q=m-n+1
    for i in range(1,m-n+2):
        for k in range(i+2,n+1):
            q-=1
            if q<0:
                exit()
            print(i,k,1000000000)

        

    
    
    
    
