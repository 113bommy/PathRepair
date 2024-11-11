a=list(map(int,input().split()))

b=input()

c=b.count('1')*a[0]+b.count('2')*a[1]+b.count('3')*a[2]+b.count('4')*a[3]

print(c)