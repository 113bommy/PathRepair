n = int(input())
d = list(map(int,input().split()))
print((sum(d)**2-sum(d[i]**2 for i in range(n)))//2)

             