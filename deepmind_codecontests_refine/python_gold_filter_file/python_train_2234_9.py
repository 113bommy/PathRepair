import math
n,m = [int(inp) for inp in input().strip().split()]

final_total_steps=-1
for i in range(int(math.floor(n/2)),-1,-1):
    b = i
    b_steps = b*2
    a_steps = n-b_steps
    a=a_steps
    total_steps = a+b
    if total_steps%m==0:
        final_total_steps = total_steps
        break
print(final_total_steps)



    
