n  = int(input())
count = 0
results = []
for i in range(1, n + 1):
   if i == 1:
      r = sum(tuple(map(int, input().split())))
   else:
      if sum(tuple(map(int, input().split()))) <= r:
         count += 1
   
print(n - count)