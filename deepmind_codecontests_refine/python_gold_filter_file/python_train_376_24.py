a=int(input())
b=int(input())
dif=abs(a-b)
m1=dif//2
m2=dif-m1
print(m1*(m1+1)//2+m2*(m2+1)//2)