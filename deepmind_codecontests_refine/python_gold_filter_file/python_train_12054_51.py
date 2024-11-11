N=int(input())

print(sum(i for i in range(1,N+1) if i%3 and  i%5))