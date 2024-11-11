N = int(input())
print(sum([0 if i%3==0 or i%5==0 else i for i in range(1,N+1)]))