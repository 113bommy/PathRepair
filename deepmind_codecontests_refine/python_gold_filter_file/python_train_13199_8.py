n = int(input())
c = max([i for i in range(1,int(n**0.5+1)) if n%i==0])
print(c+n//c-2)