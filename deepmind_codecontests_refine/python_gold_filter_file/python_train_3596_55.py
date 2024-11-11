s=0
n, a=[j for j in input().split()]
for i in range(int(n)):
    b = input()
    if eval(a+b) >= 0:
        a+=b
    else:
        s+=1
print(eval(a), s)
