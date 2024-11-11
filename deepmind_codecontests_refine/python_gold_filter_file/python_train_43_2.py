n, a, b, c =[int(x)for x in input().split()]
liter_count=0
for cc in range(c+1):
    for bb in range(b+1):
            if n-cc*2-bb >=0 and a*0.5 >= n-cc*2-bb :
               liter_count+=1
print(liter_count)