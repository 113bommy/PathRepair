p=[2]
n=int(input())+1
for i in range(3,n):
    y=1
    for j in p:y=y and i%j
    if y:p+=[i]
print(sum([2==sum([not i%j for j in p])for i in range(6,n)]))