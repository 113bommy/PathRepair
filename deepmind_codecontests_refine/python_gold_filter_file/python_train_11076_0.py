a=list(input().split('metal'))
l=len(a)
sum=0
#print(a)
for i in range(l):
    sum+=(l-i-1)*a[i].count('heavy')
print(sum)