# def is_prime(n):
#   if n == 2 or n == 3: return True
#   if n < 2 or n%2 == 0: return False
#   if n < 9: return True
#   if n%3 == 0: return False
#   r = int(n**0.5)
#   f = 5
#   while f <= r:
#     if n%f == 0: return False
#     if n%(f+2) == 0: return False
#     f +=6
#   return True
# ans=0
# for i in range(100000):
#     if is_prime(i):
#         ans+=1
#         print(i)
# print(ans)
# print(is_prime(5003))
from math import gcd as bltin_gcd

def cp(a, b):
    return bltin_gcd(a, b) == 1
n,m=[int(x) for x in input().split()]
ans=[]
yes='Possible'
no='Impossible'
def pri():
    print(yes)
    for x in ans:
        print(x[0],' ',x[1])
if m<n-1:
    print(no)
    quit()
if m==n-1:
    print(yes)
    for i in range(1,m+1):
        print(i,' ',i+1)
    quit()
for i in range(1,n):
    ans.append((i,i%n+1))
for i in range(1,n+1):
    for j in range(i+2,n+1):
        if i%2==0 and j%2==0:
            continue
        if cp(i,j):
            ans.append((i,j))
            if len(ans)==m:
                pri()
                quit()
print(no)

# connect!!!