a,b=int(input()),int(input())
if a>b:
    a,b=b,a
k,d=(b-a)//2,b-a-(b-a)//2
print(k*(k+1)//2+d*(d+1)//2)