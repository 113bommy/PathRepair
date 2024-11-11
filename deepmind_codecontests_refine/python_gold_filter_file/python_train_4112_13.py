n=int(input())
print(sum(i*max(0,min(10**i,n+1)-10**(i-1))for i in range(1,11)))