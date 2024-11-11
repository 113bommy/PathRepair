total_plucked = 0
n,v = list(map(int,input().split()))
fruits = [0] * 3002
plucked = [0] * 30002
for _ in range(n):
    a,b = list(map(int,input().split()))
    fruits[a] = fruits[a] + b
for i in range(1,3002):
   plucked[i] = fruits[i - 1] if (fruits[i - 1] <= v) else v
   if(plucked[i] < v):
       pluck = fruits[i] if (fruits[i] <= v - plucked[i]) else v - plucked[i]
       plucked[i] += pluck
       fruits[i] -= pluck
   #print(fruits[i - 1],plucked[i])
   total_plucked += plucked[i]
print(total_plucked)
 
