n=int(input())
l=[0]*10**7
s=int(n**0.65)+1
for x in range(1,s):
    for y in range(1,s-x):
        for z in range(1,s-x-y):
            l[x*x+y*y+z*z+x*y+y*z+z*x-1]+=1
for i in range(n):
    print(l[i])
