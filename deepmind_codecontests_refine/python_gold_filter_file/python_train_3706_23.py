
primes = [1]*51

i = 2
while i*i <= 51:
    
    if primes[i]==1:
        
        for j in range(i*i,51,i):
            primes[j] = 0 
    i+=1
# for i in range(51):
#     if primes[i]== 1:
#         print(i,"prime")
#     else:
#         print(i,"not prime")
    
n,m = map(int,input().split())
ans = n
for i in range(n+1,51):
    if primes[i]:
        ans = i
        break
if ans == m:
    print("YES")
else:
    print("NO")