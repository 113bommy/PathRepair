a,b =[int(a) for a in input().split()]
count=0
while a<=b:
    a=a*3
    b=b*2
    count+=1
print(count)