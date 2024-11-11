A = [int(input()) for _ in range(5)]
 
y = min([10] + [x%10 for x in A if x%10])
 
print(sum([10*(x//10 + bool(x%10)) for x in A]) -10 + y)