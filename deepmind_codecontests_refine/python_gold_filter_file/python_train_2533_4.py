def find(n):
    if n%2==0:
        return 2
    for i in range(3,int(n**0.5)+1,2):
        if n%i==0:
            return i
    return n
n=int(input())
r=n
while n!=1:
    n=n/find(n)
    r+=n
print(int(r))    